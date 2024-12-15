import os
from meta_ai_api import MetaAI
import logging

# Setup logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(message)s')

# Configuration
ai = MetaAI()



def get_file_tree(root_dir):
    file_tree = ""
    for root, dirs, files in os.walk(root_dir):
        level = root.replace(root_dir, '').count(os.sep)
        indent = '\t' * (level)
        file_tree += f"{indent}{os.path.basename(root)}/\n"
        sub_indent = '\t' * (level + 1)
        for f in files:
            file_tree += f"{sub_indent}{f}\n"
    return file_tree


def get_cpp_files(root_dir):
    cpp_files = []
    for root, _, files in os.walk(root_dir):
        for file in files:
            if file.endswith('.cpp'):
                cpp_files.append(os.path.join(root, file))
    return cpp_files


def create_readme_for_cpp_file(file_path, file_tree):
    with open(file_path, 'r') as cpp_file:
        cpp_content = cpp_file.read()

    file_name = os.path.basename(file_path)
    parent_dir = os.path.dirname(file_path)

    prompt = f"""
    Here is the file structure:
    {file_tree}
    
    Here is the content of the file {file_name}:
    ```cpp
    {cpp_content}
    ```
    
    Please create a README.md file for this C++ file.
    Please make it look professional and good, and should have all the elements of a normal readme but not very formal keep light hearted funny tone. Also return a perfectly formatted message as will be in a .md file (Topics, subtopic, lists, etc whatever else needed) and dont return absolutely anything extra, and in case there's any error in anything and you need to tell me of the issue you must use new line and then five greater than signs followed by it's message like ">>>>> Test message" and try to avoid any message as much as possible.
    """

    response = ai.prompt(message=prompt)

    readme_content = response['message']

    readme_lines = readme_content.strip().split('\n')

    with open(os.path.join(parent_dir, 'README.md'), 'w') as readme_file:
        for line in readme_lines:
            if line.startswith('>>>>>'):
                logging.info(f"AI says: {line[6:]}")
            else:
                readme_file.write(line + '\n')

def main():
    root_dir = '.'
    cpp_files = get_cpp_files(root_dir)

    total_files = len(cpp_files)
    logging.info(f"Total C++ files found: {total_files}")
    logging.info(f"All C++ files found: {cpp_files}")

    for idx, cpp_file in enumerate(cpp_files, start=1):
        parent_dir = os.path.dirname(cpp_file)
        file_tree = get_file_tree(parent_dir)
        
        if 'README.md' in os.listdir(parent_dir):
            logging.info(f"README.md already exists in {parent_dir}. Skipping.")
            continue
        
        logging.info(f"Processing file {idx}/{total_files}: {cpp_file}")
        create_readme_for_cpp_file(cpp_file, file_tree)
        logging.info(f"Completed {idx}/{total_files}: {cpp_file}")

if __name__ == '__main__':
    main()

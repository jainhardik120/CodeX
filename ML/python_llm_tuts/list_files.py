# import os

# def list_files_in_directory(directory_path):
#     """
#     Returns a list of file names in the specified directory.
    
#     Args:
#         directory_path (str): The path of the directory to list files from.
        
#     Returns:
#         list: A list of file names in the directory.
#     """
#     try:
#         # List all files and directories in the specified directory
#         items = os.listdir(directory_path)
        
#         # Filter out directories, keeping only files
#         files = [item for item in items if os.path.isfile(os.path.join(directory_path, item))]
        
#         return files
#     except FileNotFoundError:
#         print(f"The directory '{directory_path}' was not found.")
#         return []
#     except Exception as e:
#         print(f"An error occurred: {e}")
#         return []

# # Example usage
# directory_path = "C:/Users/jainh/OneDrive/Books/Educational Books"  # Replace with your directory path
# # file_list = list_files_in_directory(directory_path)
# # print(file_list)

# file_list_updated = ['Algorithms 4th Edition.pdf', 'Operating Systems: Design and Implementation.pdf', 'Structured Computer Organization1.pdf', 'Artificial Intelligence: A Modern Approach (3rd Edition).pdf', 'Artificial Intelligence: Modern Magic or Dangerous Future.pdf', 'Practical Reverse Engineering: x86, x64, ARM, Windows Kernel, Reversing Tools, and Obfuscation.pdf', 'Build Your API with Spring.pdf', 'Building Microservices: Designing Fine-Grained Systems.pdf', 'But How Do It Know? - The Basic Principles of Computers for Everyone.pdf', 'C++: The Complete Reference.pdf', 'HTML5 Cookbook.pdf', 'Computer Hacking: Beginners Guide to Hack Wireless Networks & Basic Security.pdf', 'Computer Networking: A Top-Down Approach (7th Edition).pdf', 'Computer Organization and Design: RISC-V Edition.pdf', 'Coroutines.pdf', 'DNS and BIND (5th Edition).pdf', 'Database Internals.pdf', 'Database System: Design, Implementation, and Management (12th Edition).pdf', 'Designing Data-Intensive Applications.pdf', 'Effective DevOps: Building a Culture of Collaboration, Affinity, and Tooling at Scale.pdf', 'Eloquent JavaScript.pdf', 'Hands-On Machine Learning with Scikit-Learn and Keras.pdf', 'Ghidra Software Reverse Engineering for Beginners.pdf', 'Hands-On Ethical Hacking and Network Defense.pdf', 'How to Create Tech Products Customers Love.pdf', 'Introduction to Algorithms (4th Edition).pdf', 'The Principles of Beautiful Web Design.pdf', 'Linux for Beginners: Master the Linux Operating System and Command Line from Scratch.pdf', 'Machine Learning - Tom Mitchell.pdf', 'Spring Boot: Up and Running - Building Cloud-Native Java and Kotlin Applications.pdf', 'Mastering Blockchain (2nd Edition).pdf', 'CompTIA A+ Certification: All-In-One Exam Guide.pdf', 'Crafting Interpreters.pdf', 'Object-Oriented Programming in C++.pdf', 'Operating System Concepts.pdf', 'OS Development Guide.pdf', 'Penetration Testing: A Hands-On Introduction to Hacking.pdf', 'Practical DevOps.pdf', 'Pro Git.pdf', 'Modern CMake for C++: Building, Testing, and Packaging Your Software.pdf', 'Refactoring UI.pdf', 'Site Reliability Engineering.pdf', 'Software Engineering.pdf','Structured Computer Organization.pdf', 'System Design Interview.pdf', 'System Design.pdf', 'The Art of SEO.pdf', 'The Best Interface is No Interface.pdf', 'The C++ Programming Language (4th Edition).pdf', 'Android UI Development with Jetpack Compose.pdf', 'Strategic Writing for UX: Drive Engagement, Conversion, and Retention.pdf', 'UI Design Systems Mastery.pdf', 'Understanding Distributed Systems (2nd Edition).pdf', 'Penetration Testing: A Hands-On Introduction to Hacking.pdf', 'Introduction to Cryptography with Coding Theory.pdf', 'Web Scalability for Startup Engineers.pdf', 'Computer Science Distilled: Learn the Art of Solving Computational Problems.pdf', 'The Art of SXO: Placing UX Design Methods into SEO Best Practices.pdf', 'Steganography.pdf', 'CompTIA A+ Complete Study Guide (Essentials and Practical Application).pdf', '100 Things Every Designer Needs to Know About People.pdf']

# import re

# def sanitize_filename(filename):
#     """
#     Removes invalid characters from a filename for Windows.
#     """
#     return re.sub(r'[<>:"/\\|?*]', '_', filename)

# def rename_files_in_directory(directory_path, new_names):
#     """
#     Renames files in the specified directory with the given list of new names,
#     sanitizing filenames to be compatible with the operating system.
    
#     Args:
#         directory_path (str): Path to the directory containing the files.
#         new_names (list): List of new file names (with extensions) to rename the files to.
        
#     Returns:
#         None
#     """
#     try:
#         # Get a list of all files in the directory
#         files = [f for f in os.listdir(directory_path) if os.path.isfile(os.path.join(directory_path, f))]
        
#         # Check if the number of new names matches the number of files
#         if len(files) != len(new_names):
#             print("Error: The number of new names does not match the number of files.")
#             return
        
#         for old_name, new_name in zip(files, new_names):
#             old_path = os.path.join(directory_path, old_name)
#             sanitized_new_name = sanitize_filename(new_name)
#             new_path = os.path.join(directory_path, sanitized_new_name)
#             os.rename(old_path, new_path)
#             print(f"Renamed: {old_name} -> {sanitized_new_name}")
        
#         print("All files have been renamed successfully.")
#     except Exception as e:
#         print(f"An error occurred: {e}")

# rename_files_in_directory(directory_path, file_list_updated)

import os
import re

def sanitize_filename(filename):
    """
    Removes invalid characters from a filename for Windows.
    """
    return re.sub(r'[<>:"/\\|?_*]', '', filename)

def update_file_names(directory_path, mapping):
    """
    Updates file names in the specified directory based on the given mapping.
    Skips files that do not exist and sanitizes new names.
    
    Args:
        directory_path (str): Path to the directory containing the files.
        mapping (dict): A dictionary where keys are current file names and
                        values are the new names to rename them to.
        
    Returns:
        None
    """
    try:
        for old_name, new_name in mapping.items():
            old_path = os.path.join(directory_path, old_name)
            
            # Skip if the file does not exist
            if not os.path.exists(old_path):
                print(f"File not found, skipping: {old_name}")
                continue
            
            sanitized_new_name = sanitize_filename(new_name)
            new_path = os.path.join(directory_path, sanitized_new_name)
            
            # Rename the file
            os.rename(old_path, new_path)
            print(f"Renamed: {old_name} -> {sanitized_new_name}")
        
        print("File renaming process completed.")
    except Exception as e:
        print(f"An error occurred: {e}")

# Example usage
directory_path = "C:/Users/jainh/OneDrive/Books/Educational Books"  # Replace with your directory path
mapping = {
    '100 Things Every Designer Needs to Know About People.pdf': '100 Things Every Designer Needs to Know About People - Susan Weinschenk.pdf',
    'Algorithms 4th Edition.pdf': 'Algorithms 4th Edition - Robert Sedgewick, Kevin Wayne.pdf',
    'Android UI Development with Jetpack Compose.pdf': 'Android UI Development with Jetpack Compose.pdf',
    'Artificial Intelligence_ A Modern Approach (3rd Edition).pdf': 'Artificial Intelligence: A Modern Approach (3rd Edition) - Stuart Russell, Peter Norvig.pdf',
    'Artificial Intelligence_ Modern Magic or Dangerous Future.pdf': 'Artificial Intelligence: Modern Magic or Dangerous Future - Steve Omohundro.pdf',
    'Build Your API with Spring.pdf': 'Build Your API with Spring.pdf',
    'Building Microservices_ Designing Fine-Grained Systems.pdf': 'Building Microservices: Designing Fine-Grained Systems - Sam Newman.pdf',
    'But How Do It Know_ - The Basic Principles of Computers for Everyone.pdf': 'But How Do It Know? - The Basic Principles of Computers for Everyone - J. Clark Scott.pdf',
    'C++_ The Complete Reference.pdf': 'C++: The Complete Reference - Herbert Schildt.pdf',
    'CompTIA A+ Certification_ All-In-One Exam Guide.pdf': 'CompTIA A+ Certification: All-In-One Exam Guide - Mike Meyers.pdf',
    'CompTIA A+ Complete Study Guide (Essentials and Practical Application).pdf': 'CompTIA A+ Complete Study Guide (Essentials and Practical Application).pdf',
    'Computer Hacking_ Beginners Guide to Hack Wireless Networks & Basic Security.pdf': 'Computer Hacking: Beginners Guide to Hack Wireless Networks & Basic Security.pdf',
    'Computer Networking_ A Top-Down Approach (7th Edition).pdf': 'Computer Networking: A Top-Down Approach (7th Edition) - James Kurose, Keith Ross.pdf',
    'Computer Organization and Design_ RISC-V Edition.pdf': 'Computer Organization and Design: RISC-V Edition - David Patterson, John Hennessy.pdf',
    'Computer Science Distilled_ Learn the Art of Solving Computational Problems.pdf': 'Computer Science Distilled: Learn the Art of Solving Computational Problems - Wladston Ferreira Filho.pdf',
    'Coroutines.pdf': 'Coroutines.pdf',
    'Crafting Interpreters.pdf': 'Crafting Interpreters - Bob Nystrom.pdf',
    'Database Internals.pdf': 'Database Internals - Alexey Bezzubov.pdf',
    'Database System_ Design, Implementation, and Management (12th Edition).pdf': 'Database System: Design, Implementation, and Management (12th Edition) - Carlos Coronel, Steven Morris.pdf',
    'Designing Data-Intensive Applications.pdf': 'Designing Data-Intensive Applications - Martin Kleppmann.pdf',
    'DNS and BIND (5th Edition).pdf': 'DNS and BIND (5th Edition) - Cricket Liu, Paul Albitz.pdf',
    'Effective DevOps_ Building a Culture of Collaboration, Affinity, and Tooling at Scale.pdf': 'Effective DevOps: Building a Culture of Collaboration, Affinity, and Tooling at Scale.pdf',
    'Eloquent JavaScript.pdf': 'Eloquent JavaScript - Marijn Haverbeke.pdf',
    'Ghidra Software Reverse Engineering for Beginners.pdf': 'Ghidra Software Reverse Engineering for Beginners - Chris Salls.pdf',
    'Hands-On Ethical Hacking and Network Defense.pdf': 'Hands-On Ethical Hacking and Network Defense.pdf',
    'Hands-On Machine Learning with Scikit-Learn and Keras.pdf': 'Hands-On Machine Learning with Scikit-Learn and Keras - Aurélien Géron.pdf',
    'How to Create Tech Products Customers Love.pdf': 'How to Create Tech Products Customers Love - Jackie Bavaro, Gabe Levine.pdf',
    'HTML5 Cookbook.pdf': 'HTML5 Cookbook - Christopher Schmitt, Kyle Simpson.pdf',
    'Introduction to Algorithms (4th Edition).pdf': 'Introduction to Algorithms (4th Edition) - Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein.pdf',
    'Introduction to Cryptography with Coding Theory.pdf': 'Introduction to Cryptography with Coding Theory - Wade Trappe, Lawrence C. Washington.pdf',
    'Linux for Beginners_ Master the Linux Operating System and Command Line from Scratch.pdf': 'Linux for Beginners: Master the Linux Operating System and Command Line from Scratch.pdf',
    'Machine Learning - Tom Mitchell.pdf': 'Machine Learning - Tom Mitchell.pdf',
    'Mastering Blockchain (2nd Edition).pdf': 'Mastering Blockchain (2nd Edition) - Imran Bashir.pdf',
    'Modern CMake for C++_ Building, Testing, and Packaging Your Software.pdf': 'Modern CMake for C++: Building, Testing, and Packaging Your Software - Rafał Pocztarski.pdf',
    'Object-Oriented Programming in C++.pdf': 'Object-Oriented Programming in C++ - Robert Lafore.pdf',
    'Operating System Concepts.pdf': 'Operating System Concepts - Abraham Silberschatz, Peter B. Galvin, Greg Gagne.pdf',
    'Operating Systems_ Design and Implementation.pdf': 'Operating Systems: Design and Implementation - Andrew S. Tanenbaum.pdf',
    'OS Development Guide.pdf': 'OS Development Guide.pdf',
    'Penetration Testing_ A Hands-On Introduction to Hacking.pdf': 'Penetration Testing: A Hands-On Introduction to Hacking - Georgia Weidman.pdf',
    'Practical DevOps.pdf': 'Practical DevOps - Joakim Verona.pdf',
    'Practical Reverse Engineering_ x86, x64, ARM, Windows Kernel, Reversing Tools, and Obfuscation.pdf': 'Practical Reverse Engineering: x86, x64, ARM, Windows Kernel, Reversing Tools, and Obfuscation - Bruce Dang, Alexandre Gazet, Elias Bachaalany, Sebastien Josse.pdf',
    'Pro Git.pdf': 'Pro Git - Scott Chacon, Ben Straub.pdf',
    'Refactoring UI.pdf': 'Refactoring UI - Adam Wathan, Steve Schoger.pdf',
    'Site Reliability Engineering.pdf': 'Site Reliability Engineering - Niall Richard Murphy, Betsy Beyer, Chris Jones, Jennifer Petoff.pdf',
    'Software Engineering.pdf': 'Software Engineering - Ian Sommerville.pdf',
    'Spring Boot_ Up and Running - Building Cloud-Native Java and Kotlin Applications.pdf': 'Spring Boot: Up and Running - Building Cloud-Native Java and Kotlin Applications - Mark Heckler.pdf',
    'Steganography.pdf': 'Steganography.pdf',
    'Strategic Writing for UX_ Drive Engagement, Conversion, and Retention.pdf': 'Strategic Writing for UX: Drive Engagement, Conversion, and Retention - Torrey Podmajersky.pdf',
    'Structured Computer Organization.pdf': 'Structured Computer Organization - Andrew S. Tanenbaum.pdf',
    'System Design Interview.pdf': 'System Design Interview - Alex Xu.pdf',
    'System Design.pdf': 'System Design - M.G. Ramesh.pdf',
    'The Art of SEO.pdf': 'The Art of SEO - Eric Enge, Stephan Spencer, Jessie Stricchiola.pdf',
    'The Art of SXO_ Placing UX Design Methods into SEO Best Practices.pdf': 'The Art of SXO: Placing UX Design Methods into SEO Best Practices - Jeroen van Baaren.pdf',
    'The Best Interface is No Interface.pdf': 'The Best Interface is No Interface - Golden Krishna.pdf',
    'The C++ Programming Language (4th Edition).pdf': 'The C++ Programming Language (4th Edition) - Bjarne Stroustrup.pdf',
    'The Principles of Beautiful Web Design.pdf': 'The Principles of Beautiful Web Design - Jason Beaird.pdf',
    'UI Design Systems Mastery.pdf': 'UI Design Systems Mastery.pdf',
    'Understanding Distributed Systems (2nd Edition).pdf': 'Understanding Distributed Systems (2nd Edition) - Roberto Di Pietro, Paola M. Santucci.pdf',
    'Web Scalability for Startup Engineers.pdf': 'Web Scalability for Startup Engineers - Artur Ejsmont.pdf',
}


update_file_names(directory_path, mapping)

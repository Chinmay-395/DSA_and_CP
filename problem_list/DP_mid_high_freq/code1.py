# DESCRIPTION: a python code that will find unique hyperlinks which are present in text1.txt but not in text2.txt 

import re

def extract_hyperlinks(file_content):
    # Regular expression to extract URLs
    url_regex = r'https?://(?:[-\w.]|(?:%[\da-fA-F]{2}))+'
    return set(re.findall(url_regex, file_content))

def find_unique_links(unsolved_file, solved_file):
    # Read the contents of the files
    links_solved_set = set()
    links_unsolved_set = set()
    with open(solved_file, 'r') as file:
        for line in file:
            # Assuming each line contains a link and stripping any whitespace
            link = line.strip()
            
            # Adding the link to the set
            links_solved_set.add(link)

    # print("THE solved LINK ")
    # print(links_solved_set)
    with open(unsolved_file, 'r') as file:
        for line in file:
            # Assuming each line contains a link and stripping any whitespace
            link = line.strip()
            # Adding the link to the set
            links_unsolved_set.add(link)


    # print("THE unsolved LINK ")
    # print(links_unsolved_set)
    # print(f"THE SIZE {len(links_unsolved_set)} {len(links_solved_set)}")
    # print(links1)
    # Find links unique to file1
    unique_links = links_unsolved_set - links_solved_set
    
    # print(unique_links)
    return unique_links

# Example usage
unique_hyperlinks = find_unique_links('sorted_by_freq_1.txt', 'solved_list_1.txt')


# Writing items to the file
with open('list_of_unsolved_high_freq.txt', 'w') as file:
    for item in unique_hyperlinks:
        file.write(item + '\n')
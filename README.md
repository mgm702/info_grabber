info_grabber
============

Program built in C++ that calculates various pieces of information based on the input file given to the program

This program is a command line program which can input text files, and perform various tasks based on the option selected.

These  include:

-- Report
    - This function reports information about the file to the user, and then sends a copy of the reported information 
      to a text file created inside the program folder. The various items that this function reports includes: number of 
      uppercase letters in the text file, number of lower case letters, number of spaces in the text document, and finally
      how many letters in total are found in the text file. The reported information is then sent to a new text file created 
      inside the project folder.
        
         -> ex) fileproc infile.1 outfile.1 report

-- Reverse
    - This function takes the input text file and reverses the information inside. The reversed information is then 
      sent to a new text file created inside the project folder.

         -> ex) fileproc infile.1 outfile.1 reverse

-- Histogram
    - This function takes two input text file and based on the number of times a letter is repeated in each of the files,
      the program builds a histogram of the file. It then sends this histogram to a new text file created inside the project folder. 

         -> ex) fileproc infile.1 infile.2 outfile.1 histogram

-- Encrypt
  - This function takes and input text file and an user-encryption text file. Then the program takes the text file and converts it using 
    the encryption file to create new words and phrases. This newely encrpyted file is then created inside the project folder.
      
          -> ex) fileproc infile.1 infile.2 outfile.1 encrypt
          
-- Help Menu
  - This function helps the user by displaying this content on the command line. It also explains how to interface
    with the program and the different commands possible. 
    
			  	-> ex) fileproc /?

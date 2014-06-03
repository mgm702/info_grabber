/* -----------------------------------------------------------------------------

FILE:              fileproc.cpp

DESCRIPTION:       This is my quarter term project for CS202. It is a command line tool that performs
					various functions based on the responses given on the command prompt

PARAMETERS:        If this program runs from the command line,

                     fileproc infile.1 outfile.1 report
					 fileproc /?
					 fileproc infile.1 outfile.1 reverse
					 fileproc infile.1 infile.2 outfile.1 histogram
					 fileproc infile.1 infile.2 outfile.1 encrypt

EXIT CODES:        0 = Success
                   1 = Error ...
                   2 = Error ...
                   3 = Error ...
                   4 = Error ...
                   etc.

COMPILER:          I originally created this project in Xcode for the Macbook Pro. 
					After that I transferred the code over to the Visual Studio environment

NOTES:            

MODIFICATION HISTORY:

Author                   Date                Version
---------------          ----------          --------------
Matthew Michnal         2014--02-22         Version 5

----------------------------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;
void cmd_line_error();
void command_one_test(int* p_f,int argc, char** argv);
void command_two_test(int argc, char** argv);
void command_three_test(int* p_f,int argc, char** argv);
void corrector_funct(int* p_f,int argc, char** argv);
void command_four_test(int* p_f,int argc, char** argv);
void display_help();
void reverse_function(int argc,char**argv);
void encryption_function(int argc,char**argv);
char * lower_case_Cstring (char * dest, char * src);
void report_function(int argc, char**argv);
void histogram_function(int argc, char**argv);
int main(int argc, char * argv[])
{
    int* pass_fail = 0;
	/*if(argc < 1)
    {
        cmd_line_error();
    }
    if(argc > 6)
    {
        cmd_line_error();
    }
    */
	
    command_one_test(pass_fail,argc, argv);
    command_two_test(argc, argv);
    command_three_test(pass_fail,argc, argv);
    command_four_test(pass_fail,argc, argv);
	//corrector_funct(pass_fail,argc, argv);
	
	
	return 0;
}
/* -----------------------------------------------------------------------------
FUNCTION:          command_one_test()
DESCRIPTION:       this function is meant to test if the first argument is fileproc
					this starts the entire program and must be entered in order to continue
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */


void command_one_test(int* p_f,int argc, char** argv)
{
  
        long int bfr_size =  strlen (argv[0]) + 1;
        char * bfr = new char [bfr_size];
        
        lower_case_Cstring(bfr, argv[0]);

        int compare = strcmp(argv[0], "fileproc");
        if(compare == 0)
        {
            p_f = &compare;
        }
        else
           cmd_line_error();

}
/* -----------------------------------------------------------------------------
FUNCTION:          void command_two_test(int argc, char** argv)
DESCRIPTION:	   This function is the second validation test along the way
					after fileproc has been entered, this test looks to see if the user wants to enter the help function
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

void command_two_test(int argc, char** argv)
{
    bool same = false;
    if (strlen ( argv[1] ) == 2)
    {
        int compare_results = strcmp( argv[1], "/?");
        same = ( compare_results == 0);
    }
    
    if (same)
    display_help();
}
/* -----------------------------------------------------------------------------
FUNCTION:          void command_three_test(int argc, char** argv)
DESCRIPTION:	   This function is the third validation test. If the user doesn't want to enter the help function
					Then this function assess whether they want to enter the report or reverse function based on the 
					string length of the command line argument
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

void command_three_test(int* p_f,int argc, char** argv)
{
    long int bfr_size =  strlen (argv[3]) + 1;
    char * bfr = new char [bfr_size];
    bool same = false;
    lower_case_Cstring(bfr, argv[3]);
    
    int compare = strcmp(bfr, "report");
    same = ( compare == 0);
    if(same)
    {
        p_f = &compare;
        cout << "You have entered the report function.\n";
		report_function(argc,argv);
    }

    compare = strcmp(bfr, "reverse");
    same = ( compare == 0);
    if(same)
    {
        p_f = &compare;
        cout << "You have entered the reverse function.\n";
		reverse_function(argc,argv);

	}

	compare = strcmp(bfr, "histogram");
    same = ( compare == 0);
    if(same)
    {
        p_f = &compare;
        cout << "You have entered the histogram function.\n";
		histogram_function(argc,argv);
	} 
	delete bfr;
	command_four_test(p_f,argc,argv);
}
/* -----------------------------------------------------------------------------
FUNCTION:          void command_four_test(int argc, char** argv)
DESCRIPTION:	   This is the final validation test. This test looks for the arguments histogram, and encrypt.
					It looks through the fifth argument entered in the command line and then compares it to
					the predetermined string variable.
RETURNS:           Nothing (Void Function)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

void command_four_test(int* p_f,int argc, char** argv)
{
    long int bfr_size =  strlen (argv[4]) + 1;
    char * bfr = new char [bfr_size];
    bool same = false;
    lower_case_Cstring(bfr, argv[4]);
    
    int compare = strcmp(bfr, "encrypt");
    same = ( compare == 0);
    if(same)
    {
        p_f = &compare;
        cout << "You have entered the encrypt function.\n";
		encryption_function(argc,argv);
    }
    exit (0);
}
/* -----------------------------------------------------------------------------
FUNCTION:          char * lower_case_Cstring (char * dest, char * src)
DESCRIPTION:	   This function takes characters and converts them into a lowercase character. It then returns
					these characters in the form of a string to the calling function
RETURNS:           returns a character pointer which is the lowercase equivalents of the entered parameters.
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

char * lower_case_Cstring (char * dest, char * src)
{
  
	char * p = src;
    
    for ( ; *p != 0; p++, dest++)
    
    *dest = tolower(*p);
    
    *dest = 0;
    return src;
}
/* -----------------------------------------------------------------------------
FUNCTION:          void display_help()
DESCRIPTION:	   This function if prompted displays help for the user on how to use this program. It then exits after completion.
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */
void display_help()
{
    cout << endl;
    cout << "Here is how to use our program.\n";
	cout << "You must enter the correct format in order to have the program work.\n";
	cout << "The options that you can choose from are: \n";
	cout << "fileproc report- gives a comprehensive report of the input file desired.\n";
	cout << "fileproc reverse- takes an input file and reverses it, and then sends it to a new output file.\n";
	cout << "fileproc histogram- creates a histogram out of the data collected from the individual, and then creates a visual rep.\n";
	cout << "fileproc encrypt- the user enters two input files, and the program encrypts the first one, using the second one. Then it sends it to a new output file.\n";
	exit(2);
}
/* -----------------------------------------------------------------------------
FUNCTION:          void cmd_line_error()
DESCRIPTION:	   This function is called if the user doesn't follow the correct protocol when trying to 
					access information from the program. 
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */
void cmd_line_error()
{
    cout << "Not enough command line arguments..." << endl;
    //display_help ();
    exit(1);
}
/* -----------------------------------------------------------------------------
FUNCTION:          void reverse_function(int argc,char**argv)
DESCRIPTION:	   This function is called to by the second tester function. If this function has been prompted
					then the user wishes to reverse the order of an input file and send it out to another output file. 
RETURNS:           nothing (void)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */
void reverse_function(int argc,char**argv)
{
	string data;
        
       
        {
            fstream f_input(argv[1], ios::in|ios::binary);
            char c ;
            while( f_input.get(c) )
                data += c ;
        }
        
        // reverse the string data so that it can be sent to the output file
            reverse( data.begin(), data.end() ) ;
        
        {
            ofstream o_file(argv[2], ios::out|ios::binary);
            o_file << data << endl;
        }
		exit(4);
}
/* -----------------------------------------------------------------------------
FUNCTION:          void encryption_function(int argc,char**argv)
DESCRIPTION:	   This function is called to by the last tester function. If the user has called to this function then they are
					looking to take one input file and using a seperate input file, convert the file and then send it a
					new output file that the user specifies.
RETURNS:           nothing (void)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */
void encryption_function(int argc,char**argv)
{
	
    char* dynamic_pointer;
    char* dynamic_pointer_2;
	char* dynamic_pointer_3;
    ifstream input_1(argv[1], ios::in|ios::binary);
		if(!input_1)
		{
		cout << "The program file didn't open correctly.\n";
		exit(7);
		}
        
		input_1.seekg(0L, ios::end);
        long count_holder = input_1.tellg(); 
        dynamic_pointer = new char[count_holder + 1];
		char* converter;
		converter = new char[count_holder + 1];

        for(int i = 0; i < count_holder;i++)
        {
            input_1.read(&dynamic_pointer[i],sizeof(char));
			converter[i] = dynamic_pointer[i];
        }
	
    ifstream input_2(argv[2], ios::in|ios::binary);
		if(!input_2)
		{
		cout << "The file, failed to open, the program will now exit.\n";
		exit(8);
		}
			/*
		f_input.seekg(0L, ios::end);
	num_Bytes = f_input.tellg();
    
	dynamic_pointer = new char[num_Bytes + 1];
	
	f_input.seekg(0L, ios::beg);
	*/

		input_2.seekg(0L, ios::end);
        long count_holder_2 = input_2.tellg();
		dynamic_pointer_2 = new char[count_holder_2 + 1];
		input_2.seekg(0L, ios::beg);
        char* converter_2;
		converter_2 = new char[count_holder_2 + 1];

        for(int i = 0; i < count_holder_2;i++)
        {
            input_2.read(&dynamic_pointer_2[i],sizeof(char));
			converter_2[i] = dynamic_pointer_2[i];
   
        }
		
		dynamic_pointer_3 = new char[count_holder_2 + 1];
		ofstream out_file(argv[3],ios::out|ios::binary);
          if(!out_file)
        {
			cout << "The file failed to open, the program will now exit.\n";
			exit(9);
		}
		
		for(int i = 0; i < count_holder; i++)
        {
            converter[i] = converter_2[i];
            dynamic_pointer_3[i] = converter[i];
			out_file << dynamic_pointer_3[i] << endl;
		}
	
		delete [] dynamic_pointer;
		delete [] dynamic_pointer_2;
		delete [] dynamic_pointer_3;
		delete [] converter;
		delete [] converter_2;

     exit(5);
}
/* -----------------------------------------------------------------------------
FUNCTION:          void report_function(int argc, char**argv)
DESCRIPTION:	   This function is called to by the second tester function. If the user has called to this function
					then they wish to have a report file collected on the input file and then have the report sent to 
					a new output file, that the user specifies. 
RETURNS:           nothing (void)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */
void report_function(int argc, char**argv)
{
	long num_Bytes;
    char *dynamic_pointer;
	struct stats 
	{
	int alpha;
    int lower_case;
    int upper_case;
    int space;
	};
	
	stats report_file;

	fstream f_input(argv[1], ios::in|ios::binary);

	if(!f_input)
    {
        cout << "The file did not open correctly.\n";
		exit(0);
    }
	f_input.seekg(0L, ios::end);
	num_Bytes = f_input.tellg();
    
	dynamic_pointer = new char[num_Bytes + 1];

	f_input.seekg(0L, ios::beg);
	
	
			report_file.alpha = 0;
			report_file.lower_case = 0;
			report_file.upper_case = 0;
			report_file.space = 0;

        for (int i = 0; i < num_Bytes;i++)
            {
		
				f_input.read(&dynamic_pointer[i],num_Bytes);
				if(isalpha(dynamic_pointer[i]))
                {
                  report_file.alpha++;
                }
                if(islower(dynamic_pointer[i]))
                {
                  report_file.lower_case++;
                }
                if(isupper(dynamic_pointer[i]))
                {
                  report_file.upper_case++;
				}
                if(isspace(dynamic_pointer[i]))
                {
                  report_file.space++;
				}
				if(ispunct(dynamic_pointer[i]))
				{
					i++;
				}
			
		}

	int total[26] = {0};
    for(int i = 0; i < num_Bytes; i++)
    {
        f_input.get(dynamic_pointer[i]);         // read characters one at a time
        
            if (isalpha(dynamic_pointer[i]))           // check it is a-z or A-Z
            {
                dynamic_pointer[i] = toupper(dynamic_pointer[i]);       // make it always A-Z
                
            // char A-Z has ascii code  65 to 90
            // Subtract 'A' to get
                int index = dynamic_pointer[i] - 'A';  // index in range 0 to 25;
                total[index]++;       // increment corresponding total
            }
        
    }

    int largest = total[0];
    for (int i = 0; i < 26; i++)
    {
        if(total[i] > largest)
        {
            largest = total[i];
            
        }
    }
    int smallest = total[0];
    for  (int i = 0; i < 26; i++)
    {
        if(total[i] < smallest)
        {
            smallest = total[i];
        }
    }
  
    ofstream o_file(argv[2], ios::out);
		
        o_file << "The number of bytes in this file is " << num_Bytes << endl;
        o_file << "There are " << report_file.alpha << " alphabetic letters in this file.\n";
        o_file << "There are " << report_file.lower_case << " lower case numbers in this file.\n";
        o_file << "There are " << report_file.upper_case << " upper case numbers in this file.\n";
        o_file << "There are " << report_file.space << " white spaces in this file.\n";
        o_file << "The largest number of occurrences in the file is " << largest << endl;
        o_file << "The smallest number of occurrences in the file is " << smallest << endl;
        o_file.close();

	exit(3);

}
/* -----------------------------------------------------------------------------
FUNCTION:          void histogram_function(int argc, char**argv)
DESCRIPTION:	   This function is called to by the final tester function. If the user has made it to this function
					then they wish to have a histogram created for them from the input information collected from the 
					input file. Then the histogram will be sent to a new output file that the user specifies.
RETURNS:           nothing (void)
NOTES:             Put other information here ...
----------------------------------------------------------------------------- */

void histogram_function(int argc, char**argv)
{
	char* dynamic_pointer;
	long count_holder;

	fstream f_input(*(argv + 1), ios::in|ios::binary);
	
	cout << *(argv + 1)<< endl;

	if(!f_input)
    {
        cout << "The file did not open correctly.\n";
		exit(0);
    }
	

	f_input.seekg(0L, ios::end);
	count_holder = f_input.tellg();
	dynamic_pointer = new char[count_holder + 1];
	f_input.seekg(0L, ios::beg);
        
        dynamic_pointer = new char[count_holder + 1];
        
	int total[26] = {0};
    for(int i = 0; i < count_holder; i++)
    {
		f_input.get(dynamic_pointer[i]);         // read characters one at a time
        
            if (isalpha(dynamic_pointer[i]))           // check it is a-z or A-Z
            {
                dynamic_pointer[i] = toupper(dynamic_pointer[i]);       // make it always A-Z
                
            // char A-Z has ascii code  65 to 90
            // Subtract 'A' to get
                int index = dynamic_pointer[i] - 'A';  // index in range 0 to 25;
                total[index]++;       // increment corresponding total
            }
        
    } 
	
	char num = 'A';
   
    ofstream o_file2(argv[2], ios::out|ios::binary);
    
    o_file2 << "+---------------------------+\r\n";
    
        for(int i = 0; i < 26;  i++)
        {
            if(total[i] >= 100 && total[i] < 200)
            {
                o_file2 << "|" << (num + i) << "    " << "*" << "                    |" << "\r\n";
            }
            if(total[i] >= 200 && total[i] < 300)
            {
                 o_file2 << "|" << (num + i) << "    " << "**" << "                   |" << "\r\n";
            }
            if(total[i] >= 300 && total[i] < 400)
            {
                 o_file2 << "|" << (num + i) << "    " << "***" << "                  |" << "\r\n";
            }
            if(total[i] >= 400 && total[i] < 500)
            {
                o_file2 << "|" << (num + i) << "    " << "****" << "                 |" << "\r\n";
            }
            if(total[i] >= 500 && total[i] < 600)
            {
                 o_file2 << "|" << (num + i) << "    " << "*****" << "                |" << "\r\n";
            }
            if(total[i] >= 600 && total[i] < 700)
            {
                 o_file2 << "|" << (num + i) << "    " << "******" << "               |" << "\r\n";
            }
            if(total[i] >= 700 && total[i] < 800)
            {
                 o_file2 << "|" << (num + i) << "    " << "*******" << "              |" << "\r\n";
            }
            if(total[i] >= 800 && total[i] < 900)
            {
                o_file2 << "|" << (num + i) << "    " << "********" << "             |" << "\r\n";
            }
            if(total[i] >= 900 && total[i] < 1000)
            {
                o_file2 << "|" << (num + i) << "    " << "*********" << "            |" << "\r\n";
            }
            if(total[i] >= 1000 && total[i] < 1100)
            {
                o_file2 << "|" << (num + i) << "    " << "**********" << "           |" << "\r\n";
            }
            if(total[i] >= 1100 && total[i] < 1200)
            {
                o_file2 << "|" << (num + i) << "    " << "***********" << "          |" << "\r\n";
            }
            if(total[i] >= 1200 && total[i] < 1300)
            {
                o_file2 << "|" << (num + i) << "    " << "************" << "         |" << "\r\n";
            }
            if(total[i] >= 1300 && total[i] < 1400)
            {
                o_file2 << "|" << (num + i) << "    " << "*************" << "        |" << "\r\n";
            }
            if(total[i] >= 1400 && total[i] < 1500)
            {
                o_file2 << "|" << (num + i) << "    " << "**************" <<"       |" << "\r\n";
            }
            else
            {
                o_file2 << "|" << (num + i) << "                         |" << "\r\n";
            }
            
        }
    
    o_file2 << "+---------------------------+\r\n";

    exit(6);
}
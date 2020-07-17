#include<iostream> 
#include<fstream> 
using namespace std; 
  
int main()  
{ 
   ofstream ofile;  
   ofile.open ("text.txt");  
   ofile << "geeksforgeeks" << endl; 
   cout << "Data written to file" << endl; 
   ofile.close();  
   getch();
   return 0; 
} 

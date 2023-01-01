Term Project
Data Structures and Algorithms

Name	CMS
Muhammad Sunaam	393223
Mubashir Zaman	


Submitted To: Sir Yasir Fahim
 
 
Table of Contents
Problem Statement:	3
Code Structure:	3
Models:	3
Property:	4
Owner:	4
Location:	4
Data Structures:	4
Hash Tables:	5
AVL Trees:	5
Functions:	7
Other Features:	7
Summary:	8















Problem Statement:
	The task at hand was to parse a CSV file and store the contents into appropriate data structures while reducing the complexity of searching. The CSV file contained the records of a popular Pakistani platform, called Zameen.com, for buying, selling, and renting of properties. The file contained 17 columns and the number of records was a little shy of 200,000.
Code Structure:
	To keep the design modular and flexible, we used Object-Oriented Approach. This design helps in code readability and is easier to update. All source code is maintained on GitHub and can be accessed here.
Models:
	The CSV file contained such information which could be categorized into the following:
	Property
	Owner
	Location
Thus, we created models for the following types. The classes of these models include the appropriate methods.
Property:
	The property class also contains references to objects of Owner and Location. A property object has complete information.
 

Owner:
	The owner class contains an AVL Tree of all the properties it contains. Each owner has its AVL Tree which contains references to all its properties.
 
Location:
	The Location object contains information about the geographical aspects of the property such as longitude and latitude.
 

Data Structures:
	The data structures used in this project are AVL Trees and Hash Tables (implicitly, stacks were also used).
Hash Tables:
	Firstly, hash tables with double hashing were used where the hash function was:
Hash\left(int\ key\right)=\left[key\ %\ tableSize\right]\ +\ i\ *\ [31\ -\ 31\ %\ tableSize] 
Where i is the number of collisions. 
On closer inspection, it was observed that the number of collisions was very high. Therefore we decided to use chaining instead.
In order to minimize the cost of insertion and searching, chaining with AVL Trees is used.

 

AVL Trees:
	Keeping in view the demand for reducing complexity, AVL Trees are used to store information about the owner. Three AVL Trees are used, one for storing properties inside the hash table and the other to store the owners in different sorting orders. One can be used to access the agents and the other the corresponding agencies of the properties.

 



 


 


Functions:
	Two functions for searching for an owner by an agent or by an agency have been implemented. And one function to print the entirety of the hash table with some information about the owners has been included.
 
 

Other Features:
	Other features that are worth mentioning are:
	Use of enums
	Enums have been used on multiple occasions to improve readability and ease the process.
	Parser:
	The parser employed for reading the CSV file.
 

Summary:
	This program can be employed to read large CSV files and parse data into appropriate data structures for efficient searching. It relies heavily on structured Object Oriented Concepts and the use of user-defined data types/structures.
The following Data Structures are used in this project
Data Structure	Purpose
Hash Table	To store the entirety of the properties with the help of chaining (AVL Trees) to make efficient searching.
AVL Trees	For storing each property at the index of hash table and to store the owners with different sorting orders.

![image](https://user-images.githubusercontent.com/95274859/210186932-938cb39f-77ca-484b-b67f-05f278b9db9a.png)

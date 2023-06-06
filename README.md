# CSV Parsing and Efficient Data Structures for Property Database

This project parses a large CSV file of a popular Pakistani platform, Zameen.com, for buying, selling, and renting of properties. The CSV file contains 17 columns and approximately 200,000 records. The data is stored into appropriate data structures while reducing the complexity of searching.

## Design Approach

The design uses a modular and flexible Object-Oriented Approach which enhances code readability and updateability. 

## Models

The CSV file information has been categorized into the following classes:

- **Property:** The Property class holds references to objects of Owner and Location classes, encapsulating complete information about a property.
- **Owner:** Each Owner object has an AVL Tree which contains references to all its properties.
- **Location:** The Location class encapsulates the geographical aspects of the property such as longitude and latitude.

## Data Structures

The project uses AVL Trees and Hash Tables. Stacks are implicitly used in AVL tree implementation.

- **Hash Tables:** Hash tables with double hashing were initially used. Due to high number of collisions, we switched to chaining. The Hash function used is as follows:
    ```
    Hash(int key) = [key % tableSize] + i * [31 - 31 % tableSize]
    ```
    Where i is the number of collisions. To minimize cost of insertion and searching, chaining with AVL Trees is used.
- **AVL Trees:** AVL Trees are used for storing information about the owners. Three AVL Trees are used: One for storing properties inside the hash table, and two for storing the owners in different sorting orders. One tree is used for accessing agents, and the other for accessing agencies of the properties.

## Functions

- Three search functions are implemented to look up an owner by agent, by agency, or by property ID.
- One function is included to print the entirety of the hash table with some information about the owners.

## Summary

This program efficiently reads large CSV files and parses data into appropriate data structures for efficient searching. It extensively uses structured Object Oriented Concepts and user-defined data types/structures.

| Data Structure | Purpose |
| --- | --- |
| Hash Table | To store all properties with the help of chaining (AVL Trees) for efficient searching. |
| AVL Trees | To store each property at the hash table index and to store the owners with different sorting orders. |

# DBMS-in-txt-Files

# file management system project


------------
## This project contains
1. Create 2 tables, the first for the employees and the second for the departments
	- The employees table contains [employee ID - employee name - department ID - employee rank]
	- 	The department table contains [Department ID - Department Name - Department Manager]
2. Save the data for employees and department in the following format: delimited fields, length indicator records.
3. Primary index using the Employee_ID (for Employees datafile)
4. Primary index using the Dept_ID (for Department datafile)
5. Secondary index using Dept_ID (for Employee datafile) //Dept _ID is sec. key in Employees datafile
6. Secondary index using Dept_Name (for Department datafile)
7. The user can write a query that contains fixed key words (formatted in bold below)
Examples for queries that user can write
▪ **select** all **from** Employee **where** depID **=** 'xxxx' // this query will use sec. index to get results
▪ **select** all **from** Department **where** id **=** 'xxxx' // this query will use primary. index to get results
▪ **select** name **from** Employee **where** id **=** 'xxxx' // this query will use sec. index to get results 


------------

- ### All indexes are sorted ascending
- ### Implement secondary indexes using Linked List technique.
- ### Searching in indexes is performed using binary search.
- ### To delete a record just put an * in the beginning of that record. (no need for avail list implementation)
- ### All operations (add, delete) will affect indexes.
- ### Search operations will use indexes (primary or secondary)
- ### Bind all secondary indexes with the primary index, don’t bind them by addresses directly.

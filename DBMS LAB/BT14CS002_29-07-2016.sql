--Adding CHECK constraint using which the Length of the SID is always checked when any data is entered
ALTER TABLE STUDENT_BT14CS002
ADD CHECK (LENGTH(SID) = 9);
--Inserting values in to table
INSERT INTO STUDENT_BT14CS002 VALUES ('BT14CS001','SAURAV','20-06-1995','HOSTEL-3','CSE')
--For checking the current table and it's data
SELECT * FROM STUDENT_BT14CS002;
-- Deleting the row from where the SID matches with the given ID
DELETE FROM STUDENT_BT14CS002 WHERE SID= 'BT14CS001'
--Inserting Data into the Table STUDENT_BT14CS002
INSERT INTO STUDENT_BT14CS002 VALUES('BT14CS001','Amit Pandey','','DayScholar','CSE');
INSERT INTO STUDENT_BT14CS002 VALUES('BT14CS003','Sunday Lalbiaknia','','DayScholar','CSE');
INSERT INTO STUDENT_BT14CS002 VALUES('BT14CS004','G Sai Kumar','','DayScholar','CSE');
-- To show the layout/schema of the Database Table
DESC STUDENT_BT14CS002
--For deleting row
DELETE FROM STUDENT_BT14CS002
WHERE SID = 'BT14CS001';
--For deleting a whole column 
ALTER TABLE STUDENT_BT14CS002
DROP COLUMN DOB;
--For adding a new column into the Database table
ALTER TABLE STUDENT_BT14CS002
ADD DOB DATE;
--For altering the attribute type
ALTER TABLE STUDENT_BT14CS002
MODIFY NAME CHAR(20);
--For deleting/dropping the whole table
DROP TABLE STUDENT_BT14CS002_1
--Deleted all those rows whose value of Address matched
DELETE FROM STUDENT_BT14CS002
WHERE ADDRESS = 'DayScholar';
--Creating a new table with Primary Key
CREATE TABLE DEPARTMENT_ID(
ID INT,
DEPT CHAR(3),
PRIMARY KEY(ID)
);
--For adding the NOT NULL Constraint after creating the table 
ALTER TABLE DEPARTMENT_ID MODIFY DEPT CHAR NOT NULL;
--For updating any column value at any time
UPDATE STUDENT_BT14CS002 SET DEPT=1 WHERE SID = 'BT14CS002';
--Adding Foreign Key to refer to another table
ALTER TABLE STUDENT_BT14CS002
ADD FOREIGN KEY(DEPT)
REFERENCES DEPARTMENT_ID(ID);

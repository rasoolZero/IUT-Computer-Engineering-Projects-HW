

CREATE TABLE Departments(
	Name varchar(20) NOT NULL,
	ID char(5) PRIMARY KEY,
	Budget numeric (12,2),
	Category varchar(15) Check (Category in ('Engineering','Science'))
);

CREATE TABLE Teachers(
	FirstName varchar(20) NOT NULL,
	LastName varchar(30) NOT NULL,
	ID char(7),
	BirthYear int,
	DepartmentID char(5),
	Salary numeric(7,2) Default 10000.00,
	PRIMARY KEY (ID),
	FOREIGN KEY (DepartmentID) REFERENCES Departments(ID)
);

CREATE TABLE Students(
	FirstName varchar(20) NOT NULL,
	LastName varchar(30) NOT NULL,
	StudentNumber char(7) PRIMARY KEY,
	BirthYear int,
	DepartmentID char(5),
	AdvisorID char(7),
	FOREIGN KEY (DepartmentID) REFERENCES Departments(ID),
	FOREIGN KEY (AdvisorID) REFERENCES Teachers(ID)
);

ALTER TABLE Students
ADD TotalCredits int;

CREATE TABLE Courses (
	ID char (5) PRIMARY KEY,
	Title varchar(30) NOT NULL,
	Credits int,
	DepartmentID char(5) NOT NULL,
	FOREIGN KEY (DepartmentID) REFERENCES Departments(ID),
);

CREATE TABLE Available_Courses(
	CourseID char(5) NOT NULL,
	Semester varchar(7) Check (Semester in ('fall','spring')),
	Year int NOT NULL,
	ID char (7) PRIMARY KEY,
	TeacherID char(7) NOT NULL,
	FOREIGN KEY (TeacherID) REFERENCES Teachers(ID),
	FOREIGN KEY (CourseID) REFERENCES Courses(ID)
);


CREATE TABLE Taken_Courses(
	StudentID char (7),
	CourseID char (5),
	Semester varchar(7) Check (Semester in ('fall','spring')),
	Year int,
	Grade numeric(4,2) DEFAULT 0,
	Primary KEY (StudentID,CourseID,Semester,Year),
	FOREIGN KEY (CourseID) REFERENCES Courses(ID),
	FOREIGN KEY (StudentID) REFERENCES Students(StudentNumber)
);

CREATE TABLE Prerequisites(
	CourseID char(5),
	PrereqID char(5),
	PRIMARY KEY (CourseID, PrereqID),
	FOREIGN KEY (CourseID) REFERENCES Courses(ID),
	FOREIGN KEY (PrereqID) REFERENCES Courses(ID)
);

INSERT INTO Departments VALUES ('Computer Department','ECE',1500000,'Engineering');
INSERT INTO Departments VALUES ('Physics Department','PD',2500000,'Science');

INSERT INTO Teachers VALUES ('Ali Akbar','Mortazavi','1000001',1992,'ECE',DEFAULT);
INSERT INTO Teachers VALUES ('Mohammad','Naghsh','1000002',1991,'PD',15000.00);

INSERT INTO Students VALUES ('Rasool','Kamkar','123',2001,'ECE','1000001',0);
INSERT INTO Students VALUES ('Zahra','Ali Doosti','124',2002,'ECE','1000001',3);
INSERT INTO Students VALUES ('Maryam','Amini','1231',1999,'PD','1000002',0);
INSERT INTO Students VALUES ('Ali','Moradi','1232',2000,'PD','1000002',3);

INSERT INTO Courses VALUES ('DB','Database',3,'ECE');
INSERT INTO Courses VALUES ('PHY1','Physics 1',3,'PD');
INSERT INTO Courses VALUES ('PHY2','Physics 2',3,'PD');

INSERT INTO Available_Courses VALUES('DB','fall',2021,'DBF21','1000001');
INSERT INTO Available_Courses VALUES('DB','fall',2022,'DBF22','1000001');
INSERT INTO Available_Courses VALUES('PHY1','fall',2022,'PHY1F22','1000002');
INSERT INTO Available_Courses VALUES('PHY1','fall',2021,'PHY1F21','1000002');

INSERT INTO Taken_Courses VALUES('123','DB','fall',2022,DEFAULT);
INSERT INTO Taken_Courses VALUES('1231','PHY1','fall',2022,DEFAULT);
INSERT INTO Taken_Courses VALUES('1232','PHY1','fall',2021,19.12);
INSERT INTO Taken_Courses VALUES('124','DB','fall',2021,20.00);

INSERT INTO Prerequisites VALUES('PHY1','PHY2');

SELECT StudentNumber,CONCAT(FirstName,' ',LastName) as Student,Name,Departments.ID,Budget,Category
From Students INNER JOIN Departments ON (Students.DepartmentID = Departments.ID)
WHERE StudentNumber = '123';

SELECT FirstName,LastName,CourseID,Semester,Year,
Case
when Grade+1 >= 20.00 then 20.00
Else Grade+1
End as "Increased Grade"
FROM Students Inner Join Taken_Courses ON (StudentNumber = StudentID);

SELECT * from Students
where StudentNumber not in (select StudentID from Taken_Courses where CourseID = 'DB');
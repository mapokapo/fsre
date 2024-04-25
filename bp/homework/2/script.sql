IF OBJECT_ID('Users', 'U') IS NULL
BEGIN
	CREATE TABLE Users (
		id INT PRIMARY KEY IDENTITY(1,1),
		username TEXT NOT NULL,
		email TEXT NOT NULL,
		password TEXT NOT NULL
	);
END;

IF OBJECT_ID('UserRoles', 'U') IS NULL
BEGIN
	CREATE TABLE UserRoles (
		id INT PRIMARY KEY IDENTITY(1,1),
		name TEXT NOT NULL,
		code VARCHAR(10) NOT NULL
	);
END;

IF OBJECT_ID('Settings', 'U') IS NULL
BEGIN
	CREATE TABLE Settings (
		id INT PRIMARY KEY IDENTITY(1,1),
		theme VARCHAR(10) NOT NULL,
		assignees_anonymous BIT NOT NULL,
		language VARCHAR(5) NOT NULL
	);
END;

IF OBJECT_ID('Organizations', 'U') IS NULL
BEGIN
	CREATE TABLE Organizations (
		id INT PRIMARY KEY IDENTITY(1,1),
		name TEXT NOT NULL,
		settings_id INT,
		CONSTRAINT organization_settings_id_fk FOREIGN KEY (settings_id) REFERENCES Settings(id)
	);
END;

IF OBJECT_ID('OrganizationMembers', 'U') IS NULL
BEGIN
	CREATE TABLE OrganizationMembers (
		id INT PRIMARY KEY IDENTITY(1,1),
		user_id INT NOT NULL,
		user_role_id INT,
		org_id INT NOT NULL,
		CONSTRAINT org_members_user_id_fk FOREIGN KEY (user_id) REFERENCES Users(id),
		CONSTRAINT org_members_user_role_id_fk FOREIGN KEY (user_role_id) REFERENCES UserRoles(id),
		CONSTRAINT org_members_org_id_fk FOREIGN KEY (org_id) REFERENCES Organizations(id)
	);
END;

IF OBJECT_ID('Sprints', 'U') IS NULL
BEGIN
	CREATE TABLE Sprints (
		id INT PRIMARY KEY IDENTITY(1,1),
		name TEXT NOT NULL,
		org_id INT NOT NULL,
		CONSTRAINT sprints_org_id_fk FOREIGN KEY (org_id) REFERENCES Organizations(id)
	);
END;

IF OBJECT_ID('TaskStates', 'U') IS NULL
BEGIN
	CREATE TABLE TaskStates (
		id INT PRIMARY KEY IDENTITY(1,1),
		name VARCHAR(20) NOT NULL
	);
END;

IF OBJECT_ID('Tasks', 'U') IS NULL
BEGIN
	CREATE TABLE Tasks (
		id INT PRIMARY KEY IDENTITY(1,1),
		name TEXT NOT NULL,
		description TEXT,
		sprint_id INT NOT NULL,
		state_id INT NOT NULL,
		CONSTRAINT tasks_sprint_id_fk FOREIGN KEY (sprint_id) REFERENCES Sprints(id),
		CONSTRAINT tasks_state_id_fk FOREIGN KEY (state_id) REFERENCES TaskStates(id)
);
END;

IF OBJECT_ID('TaskAssignees', 'U') IS NULL
BEGIN
	CREATE TABLE TaskAssignees (
		id INT PRIMARY KEY IDENTITY(1,1),
		task_id INT NOT NULL,
		org_member_id INT NOT NULL,
		CONSTRAINT task_assignees_task_id_fk FOREIGN KEY (task_id) REFERENCES Tasks(id),
		CONSTRAINT task_assignees_org_member_id_fk FOREIGN KEY (org_member_id) REFERENCES OrganizationMembers(id)
	);
END;
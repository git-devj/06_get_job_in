CREATE TABLE Member_Info(
id TEXT UNIQUE NOT NULL,
pin_code TEXT,
email TEXT UNIQUE,
phnum TEXT UNIQUE,
usernum INTEGER UNIQUE PRIMARY KEY AUTOINCREMENT);
# SQLite database
-----------------
### Prerequisites
- SQLite

```bash
sudo apt install sqlite3
```

### Create and fill database
```bash
$ sqlite3 database.db

sqlite> CREATE TABLE members (
   ...> id INTEGER PRIMARY KEY AUTOINCREMENT,
   ...> username TEXT NOT NULL,
   ...> password TEXT NOT NULL
   ...> );
sqlite> INSERT INTO members (username, password)
   ...> VALUES ('hakim', '12345');
```

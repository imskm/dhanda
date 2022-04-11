# Dhanda

A small and basic (atleast for initial release) business transaction tracking application for business owner (mostly for small business, retailers and shop keepers) of any business type.

This application (for now) is written entirely in `C Language` and only `Unix` based platform (Linux, MacOS, FreeBSD etc.) are supported.

This is (for now) a terminal based interactive application.

In this app you can:

- Add party details
- Search party by name and phone number
- View details of party (including transaction history)
- Delete party
- Update party
- Create transaction
- Reverse transaction (Undo a specific transaction)
- Search transaction
- View transaction statistics
- View business statistics (such as total number of parties and transactions, total amount of transaction etc.)

## How to compile and run

**Compile**

```console
make
```

**Run**

```console
./dhanda
```

**Exit from app**

```console
exit
```

## Application flow design

Architecture is very simple: `User input` -> `Update app state` -> `Render screen`.

- `User input` is basically user command given to application to perform some action
- `Update app state` updates the application according to given command, like adding new data, updating, deleting, and searching.
- `Render screen` basically showing the output of last command withing a nice and possibly pretty Text UI.

These three operations are done in a tight loop.

## Future sope


## TODO

### PARTY
- [] add created at and updated at
- [] validate add/edit input
	- [] First/Last name should only contain alpha/num/space
	- [] Amount should be integer (handle it in input), don't use scanf
	- [] Phone should be 10 digit number
- [] store sanatized input 
	- [] First/Last name should be in title case
- [] show date/time in list/show screen in ISO format

### TXN
- [] validate party ID (party must exist)
- [] store sanatized input 
	- [] First/Last name should be in title case
- [] show date/time in list/show screen in ISO format
- [] change the UI of show screen
- [] change the order of the fields


- [] Edit
	- [] on blank input take old value
	- [] show hint about what happens when user inputs blank

- [] Add new function to push error message from db layer to app struct
- [] Show that error message in UI rendering

### UI
- [] Add bg color in header and footer
- [] make space for status bar (show stats on the status bar)
- 

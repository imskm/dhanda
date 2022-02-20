# Dhanda

A small and basic (atleast for initial release) business transaction tracking application for business owner (mostly for small business, retailers and shop keepers) of any business type.
In this app you can:
This application (for now) is written entirely in `C Language` and only `Unix` based platform (Linux, MacOS, FreeBSD etc.) are supported.
This is (for now) a terminal based interactive application.

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

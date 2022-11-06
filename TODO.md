TODO
------------------

- Generate ID for party/txn
- show party
- search party
- edit party
- list txn
- Remove ID input from txn/create
- Improve txn type input
  [C]redit / [D]ebit :
- show txn

- Fix the HEADING FORMAT of every screen
  DHANDA > PARTY > LIST

- Error handling
  - Show error message
  - Check for error in file operation
  - Handle return value of every function (database layer)


TASK
------------------

### PARTY
- add created at and updated at
- validate add/edit input
	- First/Last name should only contain alpha/num/space
	- Amount should be integer (handle it in input), don't use scanf
	- Phone should be 10 digit number
- store sanitized input 
	- First/Last name should be in title case
- show date/time in list/show screen in ISO format

### TXN
- validate party ID (party must exist)
- store sanitized input 
	- First/Last name should be in title case
- show date/time in list/show screen in ISO format
- change the UI of show screen
- change the order of the fields


- Edit
	- on blank input take old value
	- show hint about what happens when user inputs blank

- Add new function to push error message from db layer to app struct
- Show that error message in UI rendering

### UI
- Add bg color in header and footer
- make space for status bar (show stats on the status bar)
- 

---

- Need to show the correct statistics on first screen.
- Remove Assertion from everywhere. Handle it.
- Party Edit is not working.
- Delete operation should ask for confirmation first before deleting the record.
- Deleting a party should delete all transactions of that party.
- Regular expression error (regcomp) should be printed using `debug_print()` function.
- Add pagination command (next, prev, last, first, mid).
- Show Party name instead of Party ID in transaction list screen.
- Show date and time (both) of creation of record in show screen.
- Show last 10 transaction below Party detail in Party Show screen.


- BUG: Garbage number is shown in place of ID NO in party/show
- BUG: CRASH: Command `show PARTY_ID` Seg Faults.
- Remove Red ERROR string at the bottom, it should be only visible when error message is shown
- BUG: Party: Add: When new party created with "New" as first name the letter "N" converted to "." (Bug in making party name title case)
- BUG: Party: Add: On failure to save the new party the party is shown on show party screen which it shouldn't.
- Remove unwanted comments
- Give space after red ERROR word shown at the bottom of the screen
- BUG: Party: Add: Success message shown in red instead of green on successful party creation
- BUG: Clear the last error message from `app` struct
- Every successful and failure operation will show success and error message and should be in green and red color respectively.
- BUG: Party: Search: Searching party doesn't work at all on name.
- BUG: Party: Search: When no match found the Error message is set as Success which should not, show "No matching result found" instead.
- BUG: Party: Search: It is possible that multiple party matches the query but the code breaks out of loop after first match.

- BUG: Txn: Add: Adding new transaction with party ID crashes the app (SIGSEGV).
  Found the bug at in file util.c at line 246 (`if(party_findbyid(app, *pid, result) == 1)`). It is due to incorrect passing of result variable.
- BUG: Txn: Add: Transaction Type is keep asking for input even thoug correct input is given. Bug in `input_txn_type()` function.
- BUG: Txn: List: UI: Transaction show output is completely messed up
- Transaction show screen should show the transaction detail as in Party Show screen.





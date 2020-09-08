first_name = input("Enter the first name:")
last_name = input("Enter the last name:")
ZIP_code = input("Enter the ZIP code:")
ID = input("Enter an employee ID:")
fn = len(first_name)
ln = len(last_name)
Zc = len(ZIP_code)
Id = len(ID)
if (fn == 0):
    print("The first name must be filled in.")
elif (fn < 2):
    print("\"%s\" is not a valid first name. It is too short." % (first_name))
if (ln == 0):
    print("The last name must be filled in.")
elif (ln < 2):
    print("\"%s\" is not a valid last name. It is too short." % (last_name))
if (Zc == 0):
    print("The ZIP code must be filled in.")
else:
    a = True
    for i in ZIP_code:
        if (not (i > '0' and i < '9')):
            a = False
            break
    if (not a):
        print("The ZIP code must be numeric.")
if (Id == 0):
    print("The ID must be filled in.")
elif (Id <= 3):
    print("%s is not a valid ID." % (ID))
else:
    a = True
    for i in range(0, Id):
        if (i < 2 and not ((ID[i] >= 'a' and ID[i] <= 'z') or (ID[i] >= 'A' and ID[i] <= 'Z'))):
            a = False
            break
        if (i == 2 and ID[i] != '-'):
            a = False
            break
        if (i > 2 and not (ID[i] > '0' and ID[i] < '9')):
            a = False
            break
    if (not a):
        print("%s is not a valid ID." % (ID))
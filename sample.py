import re
print('Y') if re.search("[a-zA-Z0-9]+@+[a-zA-Z]+\.+[com|univ|net]+$", input('Enter mail id : ')) else print('N')

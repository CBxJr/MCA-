def check_password(password):
    length_check = len(password) >= 8
    has_digit = any(char.isdigit() for char in password)
    has_upper = any(char.isupper() for char in password)
    
    print(f"Analyzing password: {password}")
    
    if length_check and has_digit and has_upper:
        return "Strong Password 💪"
    elif length_check:
        return "Moderate Password (Add numbers or capital letters) ⚠"
    else:
        return "Weak Password (Too short!) ❌"

# Test the function
my_password = input("Enter a password to test: ")
result = check_password(my_password)
print(f"Result: {result}")

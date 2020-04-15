This repo contains several small projects/challenges completed for the "C" portion of Harvard's CS50 course.
I took this course in 2019 to begin learning the fundamentals of programming prior to Tech Elevator's bootcamp (Jan, 2020 - May, 2020).

To briefly describe each project:

Credit:
    - "Credit" is a program that prompts input for a credit card number and verifies its type.
    - Some basic logic mathematically valids the card number.
    - Depending on the length & content of the number, the card can be either: Visa, American Express, or MasterCard (or INVALID)

Caesar:
    - This project reproduces Caesar's Cipher, which is a simple encryption algorithm that Julius Caesar used to obfuscate messages.
    - Using a single numeric command-line argument as a key to map an alphanumeric "shift" in content.
    - We modulo the "shift" to account for numbers that exceed the number of alphabetical characters (e.g. 1 and 27 result in the same shift)
    - Case and non-alphabetical characters remain constant throughout the encryption process.

Vigenere:
    - This project reproduces Vigenere's Cipher, which is similar to Caesar's Cipher, but more complex.
    - Using a string-based command-line argument as a key, our message is shifted, character by character, according to the key entered.
        - Only alphabetical values affect the shift. 'A' and 'a", represented by '0', don't affect the message's respective character index. 
        - 'Z' and 'z' shift the message's character by 25 places.  
        - The alphabetical values represent a shift of 0-25, respectively.
    - Numeric or symbolic values, on the other hand, have no effect on the the messages.
    - Case is preserved throughout.

Crack:
    - Using a salt, various CS50 staff members' passwords are hashed (passing the salt as a command-line argument).  The goal of "crack" is to crack them.
    - A hashed password (e.g. 50cI2vYkF0YU2) is provided, and the salt is pulled from its first two characters.
    - Using the aforementioned salt, we brute force their password.
    - The program uses a series of nested loops to generate unique combinations of characters.
    - A given sequence of characters is then hashed via the inputted salt, and the hashes are compared.  If they match, that's out password.
    - Looking back at this, this could be cleaned up quite a bit (as could all of these!)

Who-Dun-It
    - The goal of this project is to remove the "red noise/static" from a 24-bit bitmap image file (BMP) in order to reveal a name -- the person "who dun it"
    - We first reference & verify that we're reading a 24-bit, BMP 4.0 file. 
    - Once confirmed, we begin reading from the .bmp, copying the file's metadata to an output file.  
    - We then sort through each 24-bit sequence of the .bmp file, ignoring any padding.
    - Given certain RGB color values, we filter out the "red noise", writing our new RGB values to the output file, which reveal our name.

Resize: 
    - This project "resizes," or scales, an input file's 24-bit bitmap (BMP) by a user-chosen factor of "n"	

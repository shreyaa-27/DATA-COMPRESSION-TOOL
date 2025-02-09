# DATA-COMPRESSION-TOOL
COMPANY : CODTECH IT SOLUTIONS

NAME : SHREYAA

INTERN ID : CT6WMCN

DOMAIN : C PROGRAMMING

BATCH DURATION : FEBRUARY 5TH 2025 TO MARCH 20TH 2025

MENTOR NAME : NEELA SANTHOSH
This program allows the user to **compress and decompress** a file using **Run-Length Encoding (RLE)**.

---

### **How It Works**
1. **Compression:**
   - The program reads a file character by character.
   - It counts consecutive occurrences of each character.
   - It then stores the count followed by the character in the compressed file.
   - Example: `"aaaabbbcc"` → `"4a3b2c"`

2. **Decompression:**
   - The program reads the compressed file.
   - It extracts the number and character pairs.
   - It then reconstructs the original content by repeating each character accordingly.
   - Example: `"4a3b2c"` → `"aaaabbbcc"`

3. **File Display:**
   - The program can print the contents of a file before and after compression or decompression.

---

### **User Interaction**
- The user is given a choice:
  1. **Compress a new file** – The user enters content, and it gets compressed.
  2. **Decompress an existing file** – The user provides a compressed file, and the program restores the original content.

- If the user chooses **compression**, they:
  - Enter a filename.
  - Input text (typing "exit" stops input).
  - The original content is displayed.
  - A compressed version is saved in `compressed.txt` and displayed.

- If the user chooses **decompression**, they:
  - Provide the compressed file’s name.
  - The decompressed content is saved in `decompressed.txt` and displayed.

- The program ensures that file handling is properly managed, avoiding errors like missing files.

---

### **Expected Output Example**
#### **Compression:**
**User Input:**
```
aaaabbbcc
exit
```
**Compressed Output (`compressed.txt`):**
```
4a3b2c
```

#### **Decompression:**
**Compressed File Content:**
```
4a3b2c
```
**Decompressed Output (`decompressed.txt`):**
```
aaaabbbcc
```

This program is a simple and effective way to reduce file size and restore original data using RLE. 🚀

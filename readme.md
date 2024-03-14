# Encoding and Decoding Project in C++

This project contains C++ code for encoding and decoding data. It's designed to be easy to use and efficient.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

In this .zip file you have Encoding.cpp and Decode.cpp and your_input_file.txt. You have to enter your text input
in this your_input_file.txt.

### Prerequisites

There should be enough memory for computing.

## Running the tests

After pasting your input in your_input_file.txt, run Encoding.cpp and you will see the run length encoded output in the file called output.txt and corresponding remap stored into remapStore.txt.

Then, run the Decode.cpp file and you will see the decoded code in the decodedText.txt.

## How it works

Here's a quick example of how to use the encoding and decoding functions.

Encoding:
# Data Compression Algorithm

This program implements a data compression algorithm using several techniques including Burrows-Wheeler Transform (BWT), Dynamic Byte Remapping, Vertical Byte Reading, and Run-Length Encoding (RLE).

1. **Burrows-Wheeler Transform (BWT)**: The program first applies the BWT to rearrange the input string into runs of similar characters.

2. **Dynamic Byte Remapping**: The program then counts the frequency of each character in the BWT output and remaps each character to a new binary representation based on its frequency.

3. **Vertical Byte Reading**: The remapped binary strings are read vertically from left to right to form a new binary string.

4. **Run-Length Encoding (RLE)**: Finally, the program applies RLE to the output of the vertical byte reading to compress the data.

The program reads an input file, applies these transformations and compression techniques, and then outputs the compressed data. It also stores the remapping information into a separate file for later use in decompression.

Replace "your_input_file.txt" with your actual file name in the main function before running the program. The compressed output will be printed to the console and the remapping information will be stored in "remapStore.txt".

Decoding:

# Data Decompression Algorithm

This program implements a data decompression algorithm that reverses the compression process implemented by the corresponding compression program. It uses several techniques including Run-Length Decoding (RLD), Vertical Byte Reading, Dynamic Byte Remapping, and Inverse Burrows-Wheeler Transform (BWT).

1. **Run-Length Decoding (RLD)**: The program first reads the RLE encoded data from a file named "output.txt" and decodes it into a string of vertical byte readings.

2. **Vertical Byte Reading**: The vertical byte readings are converted back into the original bytes.

3. **Dynamic Byte Remapping**: The program reads a stored remap map from a file named "remapStore.txt". This map was used in the original encoding process to map byte sequences to characters. The remapped byte array is then converted back to a Burrows-Wheeler Transform (BWT) array using the remap map.

4. **Inverse Burrows-Wheeler Transform (BWT)**: Finally, the program performs the inverse BWT to get the original text.

The program reads the encoded data, applies these transformations and decompression techniques, and then outputs the decompressed data. The decompressed data is written to a file named "decodedText.txt".

Simply run the program. The decompressed output will be written to "decodedText.txt". Make sure "output.txt" and "remapStore.txt" are in the same directory as the program.

def remove_zeros_from_hexfile(input_file, output_file):
    with open(input_file, 'r') as infile, open(output_file, 'w') as outfile:
        for line in infile:
            stripped_line = line.strip()
            # Skip lines that are exactly "0", but keep lines like "00000000"
            if stripped_line != "0":
                outfile.write(line)

input_file = 'firmware.hex'  # Replace with the path to your input hex file
output_file = 'output.hex'  # Replace with the desired output file path

remove_zeros_from_hexfile(input_file, output_file)


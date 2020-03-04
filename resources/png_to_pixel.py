from PIL import Image
import sys

# print(sys.argv[1])

file_dump = 'ft_png_files/' + str(sys.argv[1])[9:-4] + '.ft_png'

print(file_dump)

# im = Image.open(sys.argv[1]) # Can be many different formats.
im = Image.open(sys.argv[1]) # Can be many different formats.
pix = im.load()
x, y = im.size # Get the width and hight of the image for iterating over
outfile = open(file_dump, 'w')

print(x)
print(y)
outfile.write("W" + str(x) + " ")
outfile.write("H" + str(y) + "\n")

for i in range(x):
	for j in range(y):
		r = pix[i, j][0]
		g = pix[i, j][1]
		b = pix[i, j][2]

		# r = pix[i, j][3]
		# g = 0
		a = pix[i, j][3]
		outfile.write("{:3d}{:3d}{:3d}{:3d}".format(a, r, g, b) + '\n')

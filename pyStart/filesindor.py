import os
path = os.getcwd()
path += os.sep+'images'+os.sep
fileList = os.listdir(path)
for f in fileList:
	extension = f[-4:]
	if os.path.isfile(path+f) and (
		extension in ['.jpg', '.png', '.bmp', 'gif', 'webp']):
		  #(
		# (f.endswith('.jpg')) or
		# (f.endswith('.png')) or 
		# (f.endswith('.bmp'))
		# ):
		print(f)
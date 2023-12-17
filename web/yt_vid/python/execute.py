content = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    {name}
    <br>
    <br>
    
    {k}
</body>
</html>"""

name = input("Enter your name: ")
k = input("Enter your passwd: ")
print(content)
htmlcontent = content.format(**locals())
print(htmlcontent)

outfile = open('frompython.html','w')
outfile.write(htmlcontent)
outfile.close()

import webbrowser, os.path

webbrowser.open('file:///'+os.path.abspath('frompython.html'))
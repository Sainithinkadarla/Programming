
import cgi

content = """
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
   
    <br>
    <br>
    
</body>
</html>"""

def update():
    form = cgi.FieldStorage()
    name = form.getfirst("name", "")
    k = form.getfirst("passwd", "")
    print(content.format(**locals()))

try:
    update()

except:
    cgi.print_exception()
# from flask import Flask
# app = Flask(__name__)

# @app.route('/helloworld/<name>')
# def hello_world(name):
#    return "Hello Worldsafds%s" % name
# # app.add_url_rule('/hello', 'hello', hello_world)

# if __name__ == '__main__':
#    app.run(debug=True)

# from flask import Flask, redirect, url_for
# app = Flask(__name__)

# @app.route('/admin')
# def hello_admin():
#    return 'Hello Admin'

# @app.route('/guest/<guest>')
# def hello_guest(guest):
#    return 'Hello %s as Guest' % guest

# @app.route('/user/<name>')
# def hello_user(name):
#    if name =='admin':
#       return redirect(url_for('hello_admin'))
#    else:
#       return redirect(url_for('hello_guest',guest = name))

# if __name__ == '__main__':
#    app.run(debug = True)

# from flask import Flask, redirect, url_for, request
# app = Flask(__name__)

# @app.route('/success/<name>')
# def success(name):
#    return 'welcome %s' % name

# @app.route('/login',methods = ['POST', 'GET'])
# def login():
#    if request.method == 'POST':
#       user = request.form['nm']
#       return redirect(url_for('success',name = user))
#    else:
#       user = request.args.get('nm')
#     #   return user
#       return redirect(url_for('success',name = user))

# if __name__ == '__main__':
#    app.run(debug = True)

from flask import Flask, render_template
app = Flask(__name__)

@app.route('/<user>')
def index(user):
   return render_template('hello.html', name=user)

if __name__ == '__main__':
   app.run(host="192.168.213.104",debug = True)
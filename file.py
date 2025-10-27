from flask import Flask,flash
app=Flask(__name__)
app.secret_key="ldd"
@app.route("/")
def hello(): 
    flash("salut  ")
    return "hell laid baroudi the ensta student should work for best idea"
app.run(debug=True)

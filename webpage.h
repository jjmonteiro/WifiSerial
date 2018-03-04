/*****************************************************************************/
/*	Serial Debugger over Wifi - UP840126 - University of Portsmouth
/*****************************************************************************/

const char HTTP_WEBSITE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
  <title>Serial Wifi Debugger</title>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">

<style>

body {
    font-family: "Arial";
    font-size: 16px;
    color: black;
    line-height: 1;
}

.flex-container {
    display: -webkit-flex;
    display: flex;
    -webkit-flex-flow: row wrap;
    flex-flow: row wrap;
    text-align: center;
}

.flex-container > * {
    padding: 15px;
    -webkit-flex: 1 100%;
    flex: 1 100%;
}

.nav {
    text-align: left;
    background:#eee;
    width: 150px;
    padding: 30px;
}

.article {
    text-align: left;
    background:#eee;
    padding: 30px;
}

header {background: grey;color:white;}
footer {background: grey;color:white;font-size: 10px;line-height: 2;}

@media all and (min-width: 768px) {
    .nav {text-align:left;-webkit-flex: 1 auto;flex:1 auto;-webkit-order:1;order:1;}
    .article {-webkit-flex:5 0px;flex:5 0px;-webkit-order:2;order:2;}
    footer {-webkit-order:3;order:3;}
}

.border{
    display: block;
    border: 2px solid #ccc;
    border-radius: 4px;
    outline:none;
}

textarea {
    width: 100%;
    height: 90%;
    margin: 5px 0;
    resize: none;
    background: white;
    box-sizing: border-box;
    min-height: 500px;
}

.textbox {
    width: 100%;
    min-height: 5%;
    margin: 5px 0;
    padding: 8px;
    font-family: "Arial";
    font-size: 14px;
    color: black;
    line-height: 1.3;
    text-decoration: none;
    box-sizing: border-box;
}

.center {text-align: center}
input:hover,input:focus {border: 2px solid grey}
</style>
</head>

<body>

<div class="flex-container">
<header>
  <h1>Serial Wifi Debugger</h1>
</header>

<!---LEFT PANEL---><nav class="nav">

<p>Informations</p>
<p class="textbox border">
	Network SSID: {{wifiSSID}}<br>
	IP Address: {{ipAddress}}<br>
	Free Memory: {{freeHeap}} Kb<br>
	Battery: {{powerSupply}} V
</p>

<br>
<p>Configurations</p>

<form action='/' method='POST' autocomplete='off' onsubmit=click1.value='Saving...'>

	<input class='textbox border' type='email' placeholder='Email Address' maxlength='40' name='text1' value='{{emailAddress}}' required>
	<input class='textbox border' type='text' placeholder='Lookup Command' maxlength='40' name='text2' value='{{faultCommand}}' required>

<br>
<p>Data Format</p> 
    
  <select class='textbox border' name='option'>
    <option value="0" {{option0}}>115200</option>
    <option value="1" {{option1}}>57600</option>
    <option value="2" {{option2}}>38400</option>
    <option value="3" {{option3}}>28800</option>
    <option value="4" {{option4}}>19200</option>
    <option value="5" {{option5}}>14400</option>
    <option value="6" {{option6}}>9600</option>
    <option value="7" {{option7}}>4800</option>
    <option value="8" {{option8}}>2400</option>
    <option value="9" {{option9}}>1200</option>
    <option value="10" {{option10}}>600</option>
    <option value="11" {{option11}}>300</option>
  </select>
  
  <br>
	<label>Ascii
	  <input type="radio" name='radio'>
	</label>
	<label>Byte
	  <input type="radio" name='radio'>
	</label>
  
  <br>
  <br>
  <br>
	<input class='textbox border' type='submit' value='Save' name='click1'>
</form>
</nav>


<!---RIGHT PANEL--->
        
<article class='article'>
<p>Buffer Contents</p>
<textarea class='border' readonly>
{{dataBuffer}}
</textarea>
</article>

<footer>Copyright &copy; 2018 Joaquim Monteiro</footer>
</div>  
</body>  
</html>



)=====";

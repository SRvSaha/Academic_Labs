<?php
//Lets connect the database....
$dbcon = @mysqli_connect("localhost","root","","Student");
if($dbcon){
    echo "Database Connection Successful<br/><br/>";
}
else{
    echo "Error! Could not connect to the database";
}

//create one array to store error message....

$error = array();

//Let assign our html form data to our variables...

//if submit button is clicked!
if(isset($_POST['submitinfo'])){
    // The _POST is checking in the submitted data and name inside _POST is related to html
    if(!empty($_POST['name']))
        // The name on the Left hand side is the PHP variable
        $name = $_POST['name'];
    else
        $error[] = "Please Enter Name!";

    if(!empty($_POST['id']))
        $id = $_POST['id'];
    else
        $error[] = "Please Enter ID/Enrollment Number!";

    if(!empty($_POST['dept']))
        $dept = $_POST['dept'];
    else
        $error[] = "Please Enter Phone Number!";
    if(!empty($_POST['dob']))
        $dob = $_POST['dob'];
    else
        $error[] = "Please Enter DOB!";
    if(!empty($_POST['phone']))
        $phone = $_POST['phone'];
    else
        $error[] = "Please Enter Your Mobile Number!";
    if(!empty($_POST['email'])){
        $email = $_POST['email'];
        if (!filter_var($email, FILTER_VALIDATE_EMAIL))
            $error[] = "Invalid email format";
    }
    else
        $error[] = "Please Enter Your Email!";
    if(!empty($_POST['address']))
        $address = $_POST['address'];
    else
        $error[] = "Please Enter Your Address!";
    if(!empty($_POST['year']))
        $year = $_POST['year'];
    else
        $error[] = "Please Enter Your Year of Study!";

// MySQL insertion of Data
    if(empty($error)){

        $query = "INSERT INTO `student_srv` (`S_NAME`,`S_MOBILE`,`S_ID`,`S_DEPT`,`S_EMAIL`,`S_DOB`,`S_ADDRESS`,`S_YEAR`) VALUES('$name','$phone','$id','$dept','$email','$dob','$address','$year')";

        $insert = mysqli_query($dbcon,$query);
        if(!$insert){
            echo "Query Failed!";
        }
        if(mysqli_affected_rows($dbcon)==1){
            echo "New Data Inserted!";
        }else{
            echo "Error !";
         }

    }else{
        echo '<ol>';

        foreach ($error as $key => $values) {

            echo '  <li>'.$values.'</li>';

        }
        echo '</ol>';
    }
    mysqli_close($dbcon);
}


?>

<!-- html form -->
<!DOCTYPE html>
<html>
<head>
    <title>Simple Data Entry</title>
</head>
<!-- CSS formatting -->
<body style="max-width:600px;
margin:auto;
align:justify;
padding:8px;
">
<!-- _PHP_SELF_ is the name of the PHP Script -->
<!-- Using the HTTP POST method for posting the information -->
<form action="<?php $_PHP_SELF; ?>" method="post">
<legend>PLEASE FILL UP!</legend><br/>
<label for="id">ENTER ID:</label><br/>
    <input type="text" name="id"><br/>
<label for="name">ENTER NAME:</label><br/>
    <input type="text" name="name"><br/>
<label for="email">ENTER EMAIL:</label><br/>
    <input type="email" name="email"><br/>
<label for="dob">ENTER DOB:</label><br/>
    <input type="date" name="dob"><br/>
<label for="address">ENTER ADDRESS:</label><br/>
    <input type="text" name="address"><br/>
<label for="phone">ENTER MOBILE NUMBER:</label><br/>
    <input type="tel" name="phone"><br/>
<label for="dept">ENTER DEPT:</label><br/>
    <input type="text" name="dept"><br/>
<label for="year">ENTER YEAR:</label><br/>
    <input type="number" name="year"><br/>
<br/>
    <input type="hidden" name="submitinfo" value="TRUE">
    <input type="submit" value="SUBMIT">
</form>
</body>
</html>

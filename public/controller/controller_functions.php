<?php
//CONTROLLER FUNCTIONS

function on_dev_team($test_user) {
    global $dev_team;
    for ($u = 0; $u < count($dev_team); $u++) {
        if ($test_user == $dev_team[$u]) {
            return true;
        }
    }
    return false;
}

function render($viewpage, $data = array()) {
    $path = 'view/'.$viewpage.'.php';
    if (file_exists($path)) {
        extract($data);
        require_once($path);
    } else {
        echo "Error, render file path does not exist <br>";
        echo "cwd = ";
        echo getcwd();
        echo "<br>path = ";
        print_r($path);
        //header('Location: index.php');
    }
}

function render_controller($viewpage, $data = array()) {
    $path = 'controller/'.$viewpage.'.php';
    if (file_exists($path)) {
        extract($data);
        require_once($path);
    } else {
        echo "Error, render file path does not exist <br>";
        echo "cwd = ";
        echo getcwd();
        echo "<br>path = ";
        print_r($path);
        //header('Location: index.php');
    }
}

function parse_status() {
    $status = "";
    if (isset($_SESSION["status"])) {
        $status_code = htmlspecialchars($_SESSION["status"]);
        if ($status_code == "uploaded_no_error") {
            $status = "Upload Successful!";
        } else if ($status_code == "upload_failed") {
            $status = "Unknown error.  Upload failed.";
        } else if ($status_code == "assignment_closed") {
            $status = "Unable to edit assignment, this assignment is closed";
        } else if ($status_code != "") {
            $status = $status_code;
        }
        $_SESSION["status"] = "";
    }
    return $status;
}

function parse_assignment_id_with_recent($class_config, $most_recent_assignment_id) {
    if (isset($_GET["assignment_id"])) {//Which homework or which lab the user wants to see
        $assignment_id = htmlspecialchars($_GET["assignment_id"]);
        $username = $_SESSION["id"];
        if (is_open_assignment($class_config, $assignment_id) || on_dev_team($username)) {
            return $assignment_id;
        }
    }
    if (trim($most_recent_assignment_id) == "" || !(is_open_assignment($class_config, $most_recent_assignment_id) || on_dev_team($username) ) ) {
        return $most_recent_assignment_id;
    }
    header("Location: index.php?page=displaymessage&semester=".check_semester()."&course=".check_course()."&assignment_id=".$most_recent_assignment_id);
    exit();

}

function parse_assignment_version_with_recent($username, $semester, $course, $assignment_id) {
    if (isset($_GET["assignment_version"])) {
        $assignment_version = htmlspecialchars($_GET["assignment_version"]);
        if (is_valid_assignment_version($username, $semester, $course, $assignment_id, $assignment_version)) {
            return $assignment_version;
        }
    }
    $assignment_version = most_recent_assignment_version($username, $semester, $course, $assignment_id);
    if (trim($assignment_version) == "" ||  trim($assignment_version) == 0){
        return $assignment_version;
    }
    else if (!is_valid_assignment_version($username, $semester, $course, $assignment_id, $assignment_version)){
        $_SESSION["status"] = "Invalid assignment_version specified";
        header("Location: index.php?page=displaymessage&semester=".$semester."&course=".$course."&assignment_id=".$assignment_id);
        exit();
    }
    else{
        header("Location: index.php?page=displaymessage&semester=".$semester."&course=".$course."&assignment_id=".$assignment_id."&assignment_version=".$assignment_version);
        exit();
    }

}

function check_semester(){
    include 'controller/defaults.php';

    if (isset($_GET["semester"])) {
        $semester = htmlspecialchars($_GET["semester"]);
        if (is_valid_semester($semester)) {
            return $semester;
        }
        $_SESSION["status"] = "Invalid semester specified";
    }
    else{
        $_SESSION["status"] = "No semester specified";
    }
    $semester = $default_semester;
    if (is_valid_semester($semester)){
        header("Location: index.php?page=displaymessage&semester=".$semester."&course=".check_course());
        exit();
    }
    return $semester;
}

function check_course(){
    include 'controller/defaults.php';

    if (isset($_GET["course"])) {
        $course = htmlspecialchars($_GET["course"]);
        if (is_valid_course($course)) {
            return $course;
        }
        $_SESSION["status"] = "Invalid course specified";
    }
    else{
        $_SESSION["status"] = "No course specified";
    }
    // FIXME: need selection page
    $course = $default_course;
    // FIXME, displaymesssage does not exist
    if (is_valid_course($course)){
        header("Location: index.php?page=displaymessage&semester=".check_semester()."&course=".$course);
        exit();
    }
    return $course;
}


function check_assignment_id($class_config){
    if (isset($_GET["assignment_id"])) {
        $username = $_SESSION["id"];
        $assignment_id = htmlspecialchars($_GET["assignment_id"]);
        if (is_open_assignment($class_config, $assignment_id) || on_dev_team($username) || trim($assignment_id)=="") {
            return $assignment_id;
        }
        $_SESSION["status"] = "Invalid assignment_id specified";
    }
    else{
        $_SESSION["status"] = "No assignment_id specified";
    }
    // FIXME, displaymesssage does not exist
    header("Location: index.php?page=displaymessage&semester=".check_semester()."&course=".check_course());
    exit();
}


function check_assignment_version($semester, $course, $assignment_id){
    if (isset($_GET["assignment_version"]) || trim(htmlspecialchars($_GET["assignment_version"])) == "") {
        $assignment_version = htmlspecialchars($_GET["assignment_version"]);
        $username = $_SESSION["id"];

        if (is_valid_assignment_version($username, $semester, $course, $assignment_id, $assignment_version)) {
            return $assignment_version;
        }
        $_SESSION["status"] = "Invalid assignment_version specified";
    }
    else{
        $_SESSION["status"] = "No assignment_version specified";
    }
    // FIXME, displaymesssage does not exist
    header("Location: index.php?page=displaymessage&semester=".$semester."&course=".$course."&assignment_id=".$assignment_id);
    exit();
}

function check_file_name($semester, $course, $assignment_id, $assignment_version){
    if (isset($_GET["file_name"])) {
        $file_name = htmlspecialchars($_GET["file_name"]);
        $username = $_SESSION["id"];

        if ($file_name == "all" || is_valid_file_name($username, $semester, $course, $assignment_id, $assignment_version, $file_name)){
            return $file_name;
        }
        $_SESSION["status"] = "Invalid file name specified";
    }
    else{
        $_SESSION["status"] = "No file name specified";
    }
    // FIXME, displaymesssage does not exist
    header("Location: index.php?page=displaymessage&semester=".$semester."&course=".$course."&assignment_id=".$assignment_id."&assignment_version=".$assignment_version);
    exit();
}


function check_class_config($semester,$course){
    $class_config = get_class_config($semester,$course);//Gets class.JSON data
    if ($class_config == NULL) {
        ?><script>alert("Configuration for this class (class.JSON) is invalid.  Quitting");</script>

        <?php
        $_SESSION["status"] = "Configuration for this class (class.JSON) is invalid";

        header("Location: index.php?page=displaymessage&semester=".$semester."&course=".$course);
        exit();
    }
    return $class_config;
}

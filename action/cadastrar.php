<?php 

	include 'BD.php';

	 $nome =  $_GET['nome'];
	 $email =  $_GET['email'];
	 $senha =  $_GET['senha'];
	 $dataNasc =  $_GET['dataNasc'];

	 $sql = "INSERT INTO Usuario(nome,email,senha,data_nasc) VALUES ('$nome','$email','$senha','$dataNasc')";
     $query = $mysqli->query($sql);	
     if ($query == true){
     	 $array = array(
     		"valor" => 0,
     		"erro" => ""
    	);
     	echo json_encode($array);
     }else{
     	$array = array(
     		"valor" => 1,
     		"erro" => mysqli_error ($mysqli)
    	);
     	echo json_encode($array);
     }
 ?>
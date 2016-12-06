<?php 

	include 'BD.php';

	 $nome =  $_GET['nome'];
	 $id_usuario =  $_GET['id_usuario'];
	 $codigo_pseudo =  $_GET['codigo_pseudo'];
     $codigo_fortran =  $_GET['codigo_fortran'];


	 $sql = "INSERT INTO Codigo(nome,id_usuario,codigo_pseudo,codigo_fortran) VALUES ('$nome','$id_usuario','$codigo_pseudo','$codigo_fortran')";
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
<?php 

	include 'BD.php';

	$email =  $_GET['email'];
	$senha =  $_GET['senha'];
	
	 $sql = "SELECT * FROM Usuario WHERE email = '$email' AND senha = '$senha'";
     $query = $mysqli->query($sql);	    
    
     if ($query->num_rows == 0){
        $array = array(
            "valor" => "",
            "erro" => 1
        );
        echo json_encode($array);
     }else{
        $row = $query->fetch_assoc();
        $array = array(
            "nome" => $row["nome"],
            "data_nasc"=>$row["data_nasc"],
            "email"=>$row["email"],
            "senha"=>$row["senha"],
            "cod"=>$row["cod"],
            "erro" => 0
        );
        echo json_encode($array);
    }
 ?>
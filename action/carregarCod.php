<?php 
	include 'BD.php';

	 $cod = $_GET['cod'];
	
	 $sql = "SELECT * FROM Codigo WHERE cod = '$cod'";
     $query = $mysqli->query($sql);	    
    
     if ($query->num_rows > 0){
     	$row = $query->fetch_assoc();
        $array = array(
            "cod" => $row["cod"],
            "id_usuario"=>$row["id_usuario"],
            "codigo_pseudo"=>$row["codigo_pseudo"],
            "codigo_fortran"=>$row["codigo_fortran"],
            "nome"=>$row["nome"],
            "erro" => 0
        );
        echo json_encode($array);
     }
 ?>
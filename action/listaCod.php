<?php 
	include 'BD.php';

	 $id_usuario = $_GET['id_usuario'];
	
	 $sql = "SELECT * FROM Codigo WHERE id_usuario = '$id_usuario'";
     $query = $mysqli->query($sql);	    
    
     if ($query->num_rows > 0){
     	$rows = array();
     	while($row = $query->fetch_assoc()) {
        	$rows[] = $row;
    	}
        echo json_encode($rows);
     }
 ?>
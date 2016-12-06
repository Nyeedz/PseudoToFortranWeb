<?php
//Função para verificar Pseudo
    $campoTexto =  $_GET['textPseudo'];

    //Escrevendo no arquivo
    $fp = fopen("../io/in.txt", "w");

    if ($fp == FALSE){
      $arrayError = array(
        "valor" => 0,
        "erro" => 1
      );
      echo json_encode($arrayError);
    }
    else{
      fwrite($fp, $campoTexto);
    }
   
    fclose($fp);

    //Executando script
    $retornoShell = shell_exec('../scripts/verificaP.sh');
    $array = array(
      "valor" => $retornoShell,
      "erro" => 0
    );
    echo json_encode($array);

    
   
?>
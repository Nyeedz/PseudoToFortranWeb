<?php
//Função para traduzir 

    //Escrevendo no arquivo
    $fp = fopen("../io/executar.f", "r");

    if ($fp == FALSE){
      $arrayError = array(
        "texto" => "",
        "erro" => 1
      );
      echo json_encode($arrayError);
    }
    else{
      while (!feof($fp)){
          $texto .= fgetc($fp);
      }
    
    }
   
    fclose($fp);


    $array = array(
      "texto" => $texto,
      "erro" => 0
    );
    echo json_encode($array);

    
   
?>
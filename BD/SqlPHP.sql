-- Cadastrar usuário
"INSERT INTO Usuario(nome,email,senha,data_nasc) VALUES ('$nome','$email','$senha','$dataNasc')";

--Carregar Código da lista
"SELECT * FROM Codigo WHERE cod = '$cod'";

--Listar todos os códigos salvos pelo usuário
"SELECT * FROM Codigo WHERE id_usuario = '$id_usuario'";

--Login
"SELECT * FROM Usuario WHERE email = '$email' AND senha = '$senha'";

--Salvar Código
"INSERT INTO Codigo(nome,id_usuario,codigo_pseudo,codigo_fortran) VALUES ('$nome','$id_usuario','$codigo_pseudo','$codigo_fortran')";


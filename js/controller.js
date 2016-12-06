app.controller("controller", function($scope,$http,$location,$rootScope){

	$scope.sair = function (){
			$rootScope.login.email = "";
			$rootScope.login.senha = "";
			$rootScope.login.data_nasc = "";
			$rootScope.login.cod = "";
			$rootScope.login.nome = "";
			$rootScope.textFortran="";
    		$rootScope.textPseudo="";
			$location.path("/login");

	}

	//Cadastro usuário
	$scope.cadastrar = function(){
		if ($scope.cadastro.senha == $scope.cadastro.csenha){
			$http({
				method: 'GET',
				url: 'action/cadastrar.php',
				headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
				params: $scope.cadastro
			}).then(function (response) {
				var data = response.data;
				if (data.valor == 0){
					alert("Cadastro realizado com sucesso!");
					$location.path("/login");
				}else{
					alert("Erro ao cadastrar\n"+data.erro);
				}
					
			});
		}
		else{
			alert("Erro: Senha e confirmação de senha, não estão iguais!");

		}
	
	};

	//Logar
	$scope.logar = function(){
		$http({
			method: 'GET',
			url: 'action/login.php',
			headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			params: $rootScope.login
		}).then(function (response) {
			var data = response.data;
			if (data.erro == 0){
				$rootScope.login.data_nasc = data.data_nasc;
				$rootScope.login.cod = data.cod;
				$rootScope.login.nome = data.nome;
				$location.path("/PseudoToFortran");		
					
			}else{
				alert("E-mail ou senha inválidos!");
			}

		});
	};


	//Função para limpar campos
	$scope.limparCampo = function(campo){
		if (campo == "textPseudo")
			$rootScope.textPseudo = "";
		else
			$rootScope.textFortran = "";
	}

	//Verificar pseudo código
	$scope.verificaP = function(){
		$http({
			 method: 'GET',
			 url: 'action/verificaP.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			 params: {textPseudo: $rootScope.textPseudo}

		}).then(function (response) {
			var data = response.data;
			if (data.erro == 1){
				alert("Erro ao executar verificação");
			}else{
				if (data.valor == 0){
					alert("O Pseudo está correto!");
				}else{
					alert("O Pseudo está incorreto!");
				}
			}
		});
	}

	//Traduzir pseudo para fortran
	$scope.traduzir = function(){
		$http({
			 method: 'GET',
			 url: 'action/traduzir.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },

		}).then(function (response) {
			var data = response.data;
			if (data.erro == 1){
				alert("Erro ao executar tradução");
			}else{
				$rootScope.textFortran = data.texto;
			}
		});
	}

	//Verificar código fortran
	$scope.verificaF = function(){
		$http({
			 method: 'GET',
			 url: 'action/verificaF.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			 params: {textFortran: $rootScope.textFortran}

		}).then(function (response) {
			var data = response.data;
			if (data.erro == 1){
				alert("Erro ao executar verificação");
			}else{
				if (data.valor == 0){
					alert("O Fortran está correto!");
				}else{
					alert("O Fortran está incorreto!");
				}
			}
		});
	}

	//Salvar Código
	$scope.salvar = function (){
		if ($rootScope.textPseudo == "" || $rootScope.textFortran == "")
			alert("Insira um código e traduza, alguma campo está vazio!");
		else{
			var nomeCod = prompt("Dê um nome para esse código:");
			var dados = {
				nome : nomeCod,
				id_usuario : $rootScope.login.cod,
				codigo_pseudo : $rootScope.textPseudo,
				codigo_fortran : $rootScope.textFortran
			}
			$http({
			 method: 'GET',
			 url: 'action/salvarCod.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			 params: dados

			}).then(function (response) {
				var data = response.data;
				if (data.valor == 0){
					alert("Códigos salvos com sucesso!");
				}else{
					alert("Erro ao salvar códigos\n"+data.erro);
				}
			});	
		}
	};

	//Ir para pagina lista 
	$scope.lista= function (){
		$location.path("/lista");	
	}

	//Atualiza listagem
	$scope.dadosCod = [];
	$http({
			 method: 'GET',
			 url: 'action/listaCod.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			 params: {id_usuario: $rootScope.login.cod}

	}).then(function (response) {
			$scope.dadosCod = response.data;
	});

	$scope.carregarCod = function (cod){
		$location.path("/PseudoToFortran");
		$http({
			 method: 'GET',
			 url: 'action/carregarCod.php',
			 headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
			 params: {cod: cod}

		}).then(function (response) {
			var dados = response.data;
			console.log(dados);
			$rootScope.textPseudo = dados.codigo_pseudo;
			$rootScope.textFortran = dados.codigo_fortran;
		});


	}

});

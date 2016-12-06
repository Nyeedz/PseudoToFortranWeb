app.config(function($routeProvider){

	//Rota padrão

	$routeProvider.otherwise("/login");


	//Rota para view home
	$routeProvider.when("/PseudoToFortran",{
		templateUrl: "views/PseudoToFortran.html",
		controller: "controller"

	});

	$routeProvider.when("/login",{
	templateUrl: "views/login.html",
	controller: "controller"

	});

	$routeProvider.when("/cadastro",{
	templateUrl: "views/cadastro.html",
	controller: "controller"

	});

	$routeProvider.when("/lista",{
	templateUrl: "views/lista.html",
	controller: "controller"

	});
});
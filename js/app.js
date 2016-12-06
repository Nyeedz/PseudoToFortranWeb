var app = angular.module('PseudoToFortran',["ngRoute",]).run(function($rootScope) {
    $rootScope.login = {
    	email : "",
    	senha : "",
    	data_nasc:"",
    	cod: "",
    	nome: ""
    }
    $rootScope.textFortran="";
    $rootScope.textPseudo="";
})
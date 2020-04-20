<?php 
include_once 'Services/AccountService.php';


$accountService = new AccountService(); 

$accounts = $accountService->GetAllAccounts();

exit( json_encode($accounts, JSON_PRETTY_PRINT) );
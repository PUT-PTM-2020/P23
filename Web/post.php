<?php 
include_once 'Services/AccountService.php';


$accountService = new AccountService(); 

exit($accountService->CreateNewAccount()->GetId());
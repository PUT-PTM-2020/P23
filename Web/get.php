<?php 
include_once 'Services/AccountService.php';

$accountId = $_GET['accountId'];

$accountService = new AccountService(); 

$account = $accountService->GetAccount($accountId);

if($account == null)
    exit("notFound");

exit($account->GetBalance());
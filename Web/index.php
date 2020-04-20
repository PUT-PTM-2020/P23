<?php 
include_once 'Services/AccountService.php';


$accountService = new AccountService(); 

$accounts = $accountService->GetAllAccounts();
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <!-- Required meta tags always come first -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <meta http-equiv="x-ua-compatible" content="ie=edge">
    <title>Material Design Bootstrap Template</title>

    <!-- Font Awesome -->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.8.1/css/all.css">

    <!-- Bootstrap core CSS -->
    <link href="css/bootstrap.min.css" rel="stylesheet">

    <!-- Material Design Bootstrap -->
    <link href="css/mdb.min.css" rel="stylesheet">

</head>

<style>
    html,
    body {
        height: 100%;
        width: 100%;
        background-color: rgb(247, 247, 247);
    }
</style>

<body class="p-5">

    <div style="">
        <div class="flex-center wow fadeIn">
            <div id="flip-card" class="flip-card flip-card rounded white z-depth-5">
                <div class="flip-card-inner">
                    <div class="card-header green white-text">
                        <h1 class="my-0 h2-responsive">PTM projekt - Konta użytkowników</h1>
                    </div>
                    <div class="card-body">

                        <table class="table table-borderless table-hover">
                            <thead class="">
                                <tr>
                                    <th scope="col">Id</th>
                                    <th scope="col">Saldo</th>
                                </tr>
                            </thead>
                            <tbody>

                                   <?php foreach($accounts as $account)
                                    {
                                        echo "<tr>";
                                        echo "<th>$account->id</th>";
                                        echo "<td>$account->balance</td>";
                                        echo "</tr>";
                                    }?>
                                    
                                                                 
                            </tbody>
                        </table>

                    </div>
                </div>

            </div>
        </div>

    </div>

</body>

</html>


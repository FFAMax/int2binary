<?php

function binary($num) {
    $result = array();
    $mask = 1;
    while ($num > 0) {
        if ($num & $mask) {
            $result[] = $mask;
            $num -= $mask;
        }
        $mask <<= 1;
    }
    echo implode(" ", $result) . PHP_EOL;
}

$options = getopt("f:");

if (isset($options['f'])) {
    $file = fopen($options['f'], 'r');
    if ($file === false) {
        echo "Error: Could not open file" . PHP_EOL;
        exit(1);
    }
    while (($line = fgets($file)) !== false) {
        $line = trim($line);
        if (is_numeric($line)) {
            $num = (int)$line;
            binary($num);
        } else {
            fprintf(STDERR, "Warning: %s is not a number\n", $line);
        }
    }
    fclose($file);
} else {
    while (($line = fgets(STDIN)) !== false) {
        $line = trim($line);
        if (is_numeric($line)) {
            $num = (int)$line;
            binary($num);
        } else {
            fprintf(STDERR, "Warning: %s is not a number\n", $line);
        }
    }
}


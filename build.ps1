
 param (
    [switch]$optimize = $false
 )

$OutputDirectory = "release"
$SourceFiles = "../src/build.c"
$OutputBinary = "muda.exe"

if ((Test-Path -Path $OutputDirectory) -eq $false) {
    New-Item -ItemType "directory" -Path $OutputDirectory | Out-Null
}

Push-Location $OutputDirectory

if (Get-Command "cl.exe" -ErrorAction SilentlyContinue) { 
   Write-Host "Found MSVC."

    $CompilerFlags = "-Od -Zi"

    if ($optimize) {
        Write-Output "Optimize build enabled."
        $CompilerFlags = "-O2"
    }

    cl -nologo -W3 -DASSERTION_HANDLED -D_CRT_SECURE_NO_WARNINGS $SourceFiles.Split(" ") $CompilerFlags.Split(" ") -EHsc -Fe"$OutputBinary"
    Write-Output "Build Finished."
} elseif (Get-Command "clang" -ErrorAction SilentlyContinue) {
    Write-Host "Found CLANG."

    $CompilerFlags = "-Od -gcodeview"

    if ($optimize) {
        Write-Output "Optimize build enabled."
        $CompilerFlags = "-O2"
    }

    clang -DASSERTION_HANDLED -Wno-switch -Wno-pointer-sign -Wno-enum-conversion -D_CRT_SECURE_NO_WARNINGS $SourceFiles.Split(" ") $CompilerFlags.Split(" ") -o "$OutputBinary"
    Write-Output "Build Finished."
} elseif (Get-Command "gcc" -ErrorAction SilentlyContinue) {
    Write-Host "Found GCC."

    $CompilerFlags = "-g"

    if ($optimize) {
        Write-Output "Optimize build enabled."
        $CompilerFlags = "-O2"
    }

    gcc -DASSERTION_HANDLED -Wno-switch -Wno-pointer-sign -Wno-enum-conversion $SourceFiles.Split(" ") $CompilerFlags.Split(" ") -o "$OutputBinary"
} else {
    Write-Error "Compiler not found."
}

Pop-Location

# Bagore's Calculator

## Continuous Integration status

| Entity | Status |
|--- |--- |
| Travis CI - Build on master branch | [![Build Status](https://travis-ci.org/bagore/calculatrice.svg?branch=master)](https://travis-ci.org/bagore/calculatrice) |

## Code Analysis status - SonarQube
| SonarQube |
|--- |
| [![Bugs](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=bugs)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=code_smells)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Coverage](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=coverage)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=ncloc)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=alert_status)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=security_rating)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Technical Debt](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=sqale_index)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |
| [![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=bagore_calculatrice&metric=vulnerabilities)](https://sonarcloud.io/dashboard?id=bagore_calculatrice) |


## To build and run

__Please note :__ This application has been developped on a Ubuntu/Unity
system. Its behaviour and appearance may vary depending on the platform.


First, clone the repository :
~~~~~~~~~~{sh}
git clone https://github.com/bagore/calculatrice
cd calculatrice
~~~~~~~~~~


Then, you can run eiher a partial build (main application only) or more
complete builds including tests and/or documentation.
~~~~~~~~~~{sh}
# Default/partial build :
make

# Complete build :
make all

# Tests build :
make tests
~~~~~~~~~~


Once the project has been built, you can run it through the Makefile (you can
also have access to generated binaries in the automatically created directory
`out/bin/`.
~~~~~~~~~~{sh}
# To run the main target :
make run-target

# To run unit tests :
make run-tests-auto
~~~~~~~~~~

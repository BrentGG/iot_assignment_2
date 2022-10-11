# IOT Assigment 2

1. :heavy_check_mark: Make a Github Action (GA) that does the following
    1. Build a project from source
    2. Packages that project into a Docker container
    3. Pushes that container into the Github container registry
2. :heavy_check_mark: Make a Terraform main.tf that does the following (in the git repo)
    1. Connects to your local Docker daemon
    2. Pulls the image built from the GA in step 1
    3. Provisions the infrastructure on your local machine
3. Bonus points
    1. :heavy_check_mark: Automatically format the Terraform code with GA
    2. Tried out Nix to build the image
    3. :heavy_check_mark: The GA creates a PR if the Terraform code isn't formatted correctly
    4. The GA is capable of creating releases trough git tags
    5. 🟠 You tried to use Terraform's remote state
    6. ...

See the [publish.yml](https://github.com/BrentGG/iot_assignment_2/blob/main/.github/workflows/publish.yml) for the Github Action of (1). The following image shows the use of Terraform of (2), also see the [main.tf](https://github.com/BrentGG/iot_assignment_2/blob/main/main.tf).
![](image.PNG?raw=true)

The [format.yml](https://github.com/BrentGG/iot_assignment_2/blob/main/.github/workflows/format.yml) formats the Terraform code and creates a pull request when formatting is necessary. An example of this is found [here](https://github.com/BrentGG/iot_assignment_2/pull/1).

As can be seen in the commented lines in [main.tf](https://github.com/BrentGG/iot_assignment_2/blob/main/main.tf), I also tried to make Terraform always pull the latest image, but I could not get this to work.

I also looked into how to use remote state, which can be seen [here](https://github.com/BrentGG/iot_assignment_2/blob/955786941ff36e8c8e8aa956e36bd059c69a24f8/.github/workflows/remote-state.yml), but this also didn't end up working.

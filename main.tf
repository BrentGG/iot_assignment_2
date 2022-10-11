terraform {
  required_providers {
    docker = {
      source  = "kreuzwerker/docker"
      version = ">= 2.13.0"
    }
  }
}

provider "docker" {
  host    = "npipe:////.//pipe//docker_engine"
}

/* tried a bunch of things to pull the latest version but doesn't work
data "docker_registry_image" "nginx" {
  name         = "ghcr.io/brentgg/iot_assignment_2/higherlower:latest"
}

resource "docker_image" "nginx" {
  name         = data.docker_registry_image.nginx.name
  pull_triggers = [data.docker_registry_image.nginx.sha256_digest]
  keep_locally = false
}*/

resource "docker_image" "nginx" {
  name         = "ghcr.io/brentgg/iot_assignment_2/higherlower:sha-d521c04"
  keep_locally = false
}

resource "docker_container" "nginx" {
  image = docker_image.nginx.latest
  name  = "iot_assigment_2"
  ports {
    internal = 80
    external = 8000
  }
  must_run   = false
  attach     = false
  stdin_open = true
  tty        = true
}

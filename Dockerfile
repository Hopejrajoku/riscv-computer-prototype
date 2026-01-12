# Use the official Tenstorrent-compatible Ubuntu image
FROM ghcr.io/tenstorrent/tt-metal/tt-metalium-ubuntu-22.04-release-amd64:latest

# Set working directory
WORKDIR /app

# Copy your local files into the container
COPY . .

# Install build essentials (if not in the image)
RUN apt-get update && apt-get install -y build-essential

# Build the solver using your Makefile
RUN make all

# Run the solver when the container starts
CMD ["./solver"]
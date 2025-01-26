import rich

def text_to_binary(text):
    """Converts text to its binary representation."""
    binary_representation = ''.join(format(ord(char), '08b') for char in text)
    return binary_representation

def main():
    """Main function to handle user input and output."""
    try:
        user_input = input("Enter the text you want to convert to binary: ")
        binary_output = text_to_binary(user_input)

        #Use rich to style the output
        rich.print(f"[bold blue]Original Text:[/bold blue] {user_input}")
        rich.print(f"[bold green]Binary Representation:[/bold green] {binary_output}")

    except Exception as e:
        rich.print(f"[bold red]An error occurred:[/bold red] {e}")


if __name__ == "__main__":
    main()



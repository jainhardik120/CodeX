import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart

# Amazon SES SMTP server configuration
SMTP_SERVER = 'email-smtp.ap-south-1.amazonaws.com'
SMTP_PORT = 587  # Use 587 for STARTTLS, 465 for TLS Wrapper

# SES credentials
sender_email = 'admin@hardikja.in'  # Must be verified in SES
receiver_email = 'hardikj0206@gmail.com'  # The recipient email
aws_access_key = 'AKIAWGD2TD27DIOBQOTB'
aws_secret_key = 'BJg9bKX9dq4Y83SVeZgnAvzRwP8uIGqOXVApn8FwxtjY'

# Email content
subject = 'Test Email from Amazon SES'
body = 'Hello, this is a test email sent using Amazon SES SMTP!'

# Create the email message
message = MIMEMultipart()
message['From'] = sender_email
message['To'] = receiver_email
message['Subject'] = subject
message.attach(MIMEText(body, 'plain'))

try:
    # Connect to the Amazon SES SMTP server
    with smtplib.SMTP(SMTP_SERVER, SMTP_PORT) as server:
        server.starttls()  # Upgrade to secure connection
        server.login(aws_access_key, aws_secret_key)  # Login to the server
        server.send_message(message)  # Send the email
        print('Email sent successfully via Amazon SES!')

except Exception as e:
    print(f'Failed to send email. Error: {e}')
